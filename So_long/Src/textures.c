/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:10:42 by marvin            #+#    #+#             */
/*   Updated: 2023/02/14 18:10:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroytextures(t_data *data)
{
	mlx_destroy_image(data->mlx.mlx_ptr, data->text.collec);
	mlx_destroy_image(data->mlx.mlx_ptr, data->text.exit);
	mlx_destroy_image(data->mlx.mlx_ptr, data->text.exit2);
	mlx_destroy_image(data->mlx.mlx_ptr, data->text.players);
	mlx_destroy_image(data->mlx.mlx_ptr, data->text.playerw);
	mlx_destroy_image(data->mlx.mlx_ptr, data->text.playera);
	mlx_destroy_image(data->mlx.mlx_ptr, data->text.playerd);
	mlx_destroy_image(data->mlx.mlx_ptr, data->text.wall);
	mlx_destroy_image(data->mlx.mlx_ptr, data->text.empty);
}

void	renderimg2(t_data *data, int i, int j)
{
	if (data->lines[i][j] == '1')
		mlx_put_image_to_window(data->mlx.mlx_ptr, \
		data->mlx.win_ptr, data->text.wall, WSIZE * j, WSIZE * i);
	else if (data->lines[i][j] == '0')
		mlx_put_image_to_window(data->mlx.mlx_ptr, \
		data->mlx.win_ptr, data->text.empty, WSIZE * j, WSIZE * i);
	else if (data->lines[i][j] == 'C')
		mlx_put_image_to_window(data->mlx.mlx_ptr, \
		data->mlx.win_ptr, data->text.collec, WSIZE * j, WSIZE * i);
	else if (data->lines[i][j] == 'E')
		mlx_put_image_to_window(data->mlx.mlx_ptr, \
		data->mlx.win_ptr, data->text.exit, WSIZE * j, WSIZE * i);
	else if (data->lines[i][j] == 'P')
		mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr, \
		data->text.players, WSIZE * j, WSIZE * i);
}

void	renderimg(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->alt)
	{
		j = -1;
		while (++j < data->comp)
			renderimg2(data, i, j);
	}
}

void	putimg2(t_data *data)
{
	if (!data->text.wall || !data->text.empty || \
	!data->text.collec || !data->text.exit || !data->text.players)
		error_msg("Missing images", data);
	renderimg(data);
}

void	putimg(t_data *data)
{
	int	imgsize;

	imgsize = WSIZE;
	data->text.wall = mlx_xpm_file_to_image(data->mlx.mlx_ptr, \
	"./Textures/Wall.xpm", &imgsize, &imgsize);
	data->text.empty = mlx_xpm_file_to_image(data->mlx.mlx_ptr, \
	"./Textures/Empty.xpm", &imgsize, &imgsize);
	data->text.collec = mlx_xpm_file_to_image(data->mlx.mlx_ptr, \
	"./Textures/Colect.xpm", &imgsize, &imgsize);
	data->text.exit = mlx_xpm_file_to_image(data->mlx.mlx_ptr, \
	"./Textures/Exit.xpm", &imgsize, &imgsize);
	data->text.exit2 = mlx_xpm_file_to_image(data->mlx.mlx_ptr, \
	"./Textures/Exit2.xpm", &imgsize, &imgsize);
	data->text.players = mlx_xpm_file_to_image(data->mlx.mlx_ptr, \
	"./Textures/Player.xpm", &imgsize, &imgsize);
	data->text.playerw = mlx_xpm_file_to_image(data->mlx.mlx_ptr, \
	"./Textures/Playeru.xpm", &imgsize, &imgsize);
	data->text.playera = mlx_xpm_file_to_image(data->mlx.mlx_ptr, \
	"./Textures/Playere.xpm", &imgsize, &imgsize);
	data->text.playerd = mlx_xpm_file_to_image(data->mlx.mlx_ptr, \
	"./Textures/Playerd.xpm", &imgsize, &imgsize);
	putimg2(data);
}
