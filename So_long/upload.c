/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upload.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:37:47 by lugoncal          #+#    #+#             */
/*   Updated: 2023/05/17 21:01:42 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	uploadmov(t_data *data, int mov)
{
	char	*move;

	move = ft_itoa(mov);
	ft_putstr_fd("Move: ", 1);
	ft_putstr_fd(move, 1);
	ft_putstr_fd("\n", 1);
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.win_ptr, \
	50, 75, 0x00000000, "Move: ");
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.win_ptr, \
	80, 75, 0x00000000, move);
	free(move);
}

void	uploadplayer(t_data *data, int i, int j, int p)
{
	if (p == 1)
		mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr, \
		data->mlx.player, WSIZE * j, WSIZE * i);
	else if (p == 2)
		mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr, \
		data->mlx.player2, WSIZE * j, WSIZE * i);
	else if (p == 3)
		mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr, \
		data->mlx.player3, WSIZE * j, WSIZE * i);
	else if (p == 4)
		mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr, \
		data->mlx.player4, WSIZE * j, WSIZE * i);
}

void	uploadimg(t_data *data, void *text, int i, int j)
{
	mlx_put_image_to_window(data->mlx.mlx_ptr, \
	data->mlx.win_ptr, text, WSIZE * j, WSIZE * i);
}

int	uploadmap(t_data *data, int p)
{
	int		i;
	int		j;

	i = -1;
	while (++i < data->width)
	{
		j = -1;
		while (++j < data->length)
        {
	        if (data->map[i][j] == '1')
	        	uploadimg(data, data->mlx.wall, i, j);
        	else if (data->map[i][j] == '0')
        		uploadimg(data, data->mlx.empty, i, j);
        	else if (data->map[i][j] == 'C')
        		uploadimg(data, data->mlx.coin, i, j);
	        else if (data->map[i][j] == 'E' && data->coin != 0)
	        	uploadimg(data, data->mlx.exit, i, j);
	        else if (data->map[i][j] == 'E' && data->coin == 0)
	        	uploadimg(data, data->mlx.exit2, i, j);
	        else if (data->map[i][j] == 'P')
	        	uploadplayer(data, i, j, p);
        }
	}
	uploadmov(data, ++data->mov);
	return (0);
}