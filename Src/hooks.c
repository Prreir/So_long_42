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

void	playermove(t_data *data, int y, int x, int p)
{
	int		last_x;
	int		last_y;

	last_x = data->itens.player_x;
	last_y = data->itens.player_y;
	if (data->lines[y][x] == 'E' && data->itens.collec == 0)
	{
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

int		keypress(int keycode, t_data *data)
{
	if (keycode == 119 || keycode == 65362)
		playermove(data, data->itens.player_y - 1, data->itens.player_x, PLAYERW);
	else if (keycode == 115 || keycode == 65364)
		playermove(data, data->itens.player_y + 1, data->itens.player_x, PLAYERS);
	else if (keycode == 97 || keycode == 65361)
		playermove(data, data->itens.player_y, data->itens.player_x - 1, PLAYERA);
	else if (keycode == 100 || keycode == 65363)
		playermove(data, data->itens.player_y, data->itens.player_x + 1, PLAYERD);
	else if (keycode == 65307)
		killgame(data);
	return (0);
}

int		closex(void *data)
{
	killgame(data);
	return (0);
}
