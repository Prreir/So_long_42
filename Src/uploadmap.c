/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uploadmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:36:43 by lugoncal          #+#    #+#             */
/*   Updated: 2023/02/15 13:36:44 by lugoncal         ###   ########.fr       */
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

void	uploadplayer(t_data *data, int y, int x, int p)
{
	if (p == 1)
		mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr, \
		data->textures.players, WSIZE * x, WSIZE * y);
	else if (p == 2)
		mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr, \
		data->textures.playerw, WSIZE * x, WSIZE * y);
	else if (p == 3)
		mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr, \
		data->textures.playera, WSIZE * x, WSIZE * y);
	else if (p == 4)
		mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr, \
		data->textures.playerd, WSIZE * x, WSIZE * y);
}

void	uploadimg(t_data *data, void *textures, int y, int x)
{
	mlx_put_image_to_window(data->mlx.mlx_ptr, \
	data->mlx.win_ptr, textures, WSIZE * x, WSIZE * y);
}

void	uploadtextures(t_data *data, int y, int x, int p)
{
	if (data->lines[y][x] == '1')
		uploadimg(data, data->textures.wall, y, x);
	else if (data->lines[y][x] == '0')
		uploadimg(data, data->textures.empty, y, x);
	else if (data->lines[y][x] == 'C')
		uploadimg(data, data->textures.collec, y, x);
	else if (data->lines[y][x] == 'E' && data->itens.collec != 0)
		uploadimg(data, data->textures.exit, y, x);
	else if (data->lines[y][x] == 'E' && data->itens.collec == 0)
		uploadimg(data, data->textures.exit2, y, x);
	else if (data->lines[y][x] == 'P')
		uploadplayer(data, y, x, p);
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
