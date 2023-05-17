/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:32:53 by lugoncal          #+#    #+#             */
/*   Updated: 2023/05/17 21:06:20 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	getX(void *data)
{
	killgame(data);
	return (0);
}

void	playermove(t_data *data, int i, int j, int p)
{
	int		last_x;
	int		last_y;

	last_x = data->p.x;
	last_y = data->p.y;
	if (data->map[i][j] == 'E' && data->coin == 0)
	{
		uploadmov(data, ++data->mov);
		ft_putstr_fd("WIN!\n", 1);
		killgame(data);
	}
	else if (data->map[i][j] != '1')
	{
		data->map[last_y][last_x] = '0';
		if (data->map[i][j] == 'C')
			data->coin--;
		data->p.x = j;
		data->p.y = i;
		data->map[i][j] = 'P';
		if (data->map[data->e.y][data->e.x] != 'P')
			data->map[data->e.y][data->e.x] = 'E';
		uploadmap(data, p);
	}
}

int		getkeys(int	keycode, t_data *data)
{
	if (keycode == 119 || keycode == 65362)
		playermove(data, data->p.y - 1, data->p.x, 4);
	else if (keycode == 115 || keycode == 65364)
		playermove(data, data->p.y + 1, data->p.x, 1);
	else if (keycode == 97 || keycode == 65361)
		playermove(data, data->p.y, data->p.x - 1, 3);
	else if (keycode == 100 || keycode == 65363)
		playermove(data, data->p.y, data->p.x + 1, 2);
	else if (keycode == 65307)
		killgame(data);
	return (0);
}

void	getimg(t_data *data)
{
	int		size;

	size = WSIZE;
	data->mlx.coin = mlx_xpm_file_to_image(data->mlx.mlx_ptr, COIN, &size, &size);
	data->mlx.exit = mlx_xpm_file_to_image(data->mlx.mlx_ptr, EXIT, &size, &size);
	data->mlx.exit2 = mlx_xpm_file_to_image(data->mlx.mlx_ptr, EXIT2, &size, &size);
	data->mlx.player = mlx_xpm_file_to_image(data->mlx.mlx_ptr, PLAYER, &size, &size);
	data->mlx.player2 = mlx_xpm_file_to_image(data->mlx.mlx_ptr, PLAYER2, &size, &size);
	data->mlx.player3 = mlx_xpm_file_to_image(data->mlx.mlx_ptr, PLAYER3, &size, &size);
	data->mlx.player4 = mlx_xpm_file_to_image(data->mlx.mlx_ptr, PLAYER4, &size, &size);
	data->mlx.wall = mlx_xpm_file_to_image(data->mlx.mlx_ptr, WALL, &size, &size);
	data->mlx.empty = mlx_xpm_file_to_image(data->mlx.mlx_ptr, EMPTY, &size, &size);
}

void	getcoords(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->width)
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 'P')
			{
				data->p.x = j;
				data->p.y = i;
				data->player++;
			}
			else if (data->map[i][j] == 'C')
				data->coin++;
			else if (data->map[i][j] == 'E')
			{
				data->e.x = j;
				data->e.y = i;
				data->exit++;
			}
		}
	}
}
