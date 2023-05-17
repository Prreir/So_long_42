/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:15:21 by lugoncal          #+#    #+#             */
/*   Updated: 2023/05/17 21:07:27 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checkarg(t_data *data, int argc, char *str)
{
	int	i;

	if (argc != 2)
		error_msg("Too many or few arguments", data);
	else
	{
		i = (ft_strlen(str) - 4);
		if (ft_strncmp(".ber", &str[i], 4) != 0)
			error_msg("The file is not a .ber", data);
	}
}

void	init(t_data *data)
{
	data->length = 0;
	data->width = 0;
	data->map = NULL;
	data->dup = NULL;
	data->coin = 0;
	data->exit = 0;
	data->player = 0;
	data->mov = 0;
	data->p.x = 0;
	data->p.y = 0;
	data->e.y = 0;
	data->e.x = 0;
	data->mlx.mlx_ptr = 0;
	data->mlx.win_ptr = 0;
	data->mlx.coin = 0;
	data->mlx.exit = 0;
	data->mlx.exit2 = 0;
	data->mlx.player = 0;
	data->mlx.player2 = 0;
	data->mlx.player3 = 0;
	data->mlx.player4 = 0;
	data->mlx.wall = 0;
	data->mlx.empty = 0;
}

int	main(int argc, char **argv)
{
	t_data	data;

	init(&data);
	checkarg(&data, argc, argv[1]);
	getsize(&data, argv[1]);
	getmap(&data, argv[1]);
	validmap(&data);
	initmlx(&data);
	getimg(&data);
	renderimg(&data);
	mlx_hook(data.mlx.win_ptr, 2, (1L << 0), getkeys, &data);
	mlx_hook(data.mlx.win_ptr, 17, (1L << 2), getX, &data);
	mlx_loop(data.mlx.mlx_ptr);
	freemap(&data);
	return (0);
}
