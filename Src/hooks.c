/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:22:07 by lugoncal          #+#    #+#             */
/*   Updated: 2023/02/15 10:22:08 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	collect(t_data *data)
{
	int		i;
	int		j;

	i = -1;
	while (++i < data->alt)
	{
		j = -1;
		while (++j < data->comp)
		{
			if (data->lines[i][j] == 'C')
			{
				mlx_put_image_to_window(data->mlx.mlx_ptr, \
				data->mlx.win_ptr, data->textures.collec, WSIZE * j, WSIZE * i);
				usleep(40000);
				mlx_put_image_to_window(data->mlx.mlx_ptr, \
				data->mlx.win_ptr, data->textures.collec2, WSIZE * j, WSIZE * i);
			}
		}
	}
	return (0);
}

void	playermove(t_data *data, int y, int x, int p)
{
	int		last_x;
	int		last_y;

	last_x = data->itens.player_x;
	last_y = data->itens.player_y;
	if (data->lines[y][x] == 'E' && data->itens.collec == 0)
	{
		uploadmov(data, ++data->mov);
		ft_putstr_fd("WIN!\n", 1);
		killgame(data);
	}
	else if (data->lines[y][x] != '1')
	{
		data->lines[last_y][last_x] = '0';
		if (data->lines[y][x] == 'C')
			data->itens.collec--;
		data->itens.player_x = x;
		data->itens.player_y = y;
		data->lines[y][x] = 'P';
		if (data->lines[data->itens.exit_y][data->itens.exit_x] != 'P')
			data->lines[data->itens.exit_y][data->itens.exit_x] = 'E';
		uploadmap(data, p);
	}
}

int	keypress(int keycode, t_data *data)
{
	if (keycode == 119 || keycode == 65362)
		playermove(data, data->itens.player_y - 1, data->itens.player_x, 2);
	else if (keycode == 115 || keycode == 65364)
		playermove(data, data->itens.player_y + 1, data->itens.player_x, 1);
	else if (keycode == 97 || keycode == 65361)
		playermove(data, data->itens.player_y, data->itens.player_x - 1, 3);
	else if (keycode == 100 || keycode == 65363)
		playermove(data, data->itens.player_y, data->itens.player_x + 1, 4);
	else if (keycode == 65307)
		killgame(data);
	return (0);
}

int	closex(void *data)
{
	killgame(data);
	return (0);
}
