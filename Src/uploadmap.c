/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uploadmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:36:43 by lugoncal          #+#    #+#             */
/*   Updated: 2023/02/21 13:21:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
		data->textures.players, WSIZE * j, WSIZE * i);
	else if (p == 2)
		mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr, \
		data->textures.playerw, WSIZE * j, WSIZE * i);
	else if (p == 3)
		mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr, \
		data->textures.playera, WSIZE * j, WSIZE * i);
	else if (p == 4)
		mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr, \
		data->textures.playerd, WSIZE * j, WSIZE * i);
}

void	uploadimg(t_data *data, void *textures, int i, int j)
{
	mlx_put_image_to_window(data->mlx.mlx_ptr, \
	data->mlx.win_ptr, textures, WSIZE * j, WSIZE * i);
}

void	uploadtextures(t_data *data, int i, int j, int p)
{
	if (data->lines[i][j] == '1')
		uploadimg(data, data->textures.wall, i, j);
	else if (data->lines[i][j] == '0')
		uploadimg(data, data->textures.empty, i, j);
	else if (data->lines[i][j] == 'C')
		uploadimg(data, data->textures.collec, i, j);
	else if (data->lines[i][j] == 'E' && data->itens.collec != 0)
		uploadimg(data, data->textures.exit, i, j);
	else if (data->lines[i][j] == 'E' && data->itens.collec == 0)
		uploadimg(data, data->textures.exit2, i, j);
	else if (data->lines[i][j] == 'P')
		uploadplayer(data, i, j, p);
}

int	uploadmap(t_data *data, int p)
{
	int		i;
	int		j;

	i = -1;
	while (++i < data->alt)
	{
		j = -1;
		while (++j < data->comp)
			uploadtextures(data, i, j, p);
	}
	uploadmov(data, ++data->mov);
	return (0);
}
