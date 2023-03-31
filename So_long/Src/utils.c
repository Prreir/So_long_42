/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:13:11 by lugoncal          #+#    #+#             */
/*   Updated: 2023/02/21 13:14:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	killgame(t_data *data)
{
	destroytextures(data);
	mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.win_ptr);
	mlx_destroy_display(data->mlx.mlx_ptr);
	free(data->mlx.mlx_ptr);
	freemap(data);
	exit(0);
}

void	freemap(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->alt)
	{
		free(data->lines[i]);
		free(data->clone[i]);
		i++;
	}
	free(data->clone);
	free(data->lines);
}

void	error_msg(char *msg, t_data *data)
{
	ft_putstr_fd("Error: ", 1);
	ft_putstr_fd(msg, 1);
	ft_putstr_fd("\n", 1);
	if (data->lines)
		freemap(data);
	exit(1);
}

void	iniciar(t_data *data)
{
	data->comp = 0;
	data->alt = 0;
	data->lines = NULL;
	data->clone = NULL;
	data->mov = 0;
	data->itens.collec = 0;
	data->itens.exit = 0;
	data->itens.exit_x = 0;
	data->itens.exit_y = 0;
	data->itens.player = 0;
	data->itens.player_x = 0;
	data->itens.player_y = 0;
	data->text.wall = 0;
	data->text.empty = 0;
	data->text.collec = 0;
	data->text.exit = 0;
	data->text.exit2 = 0;
	data->text.players = 0;
	data->text.playerw = 0;
	data->text.playera = 0;
	data->text.playerd = 0;
}
