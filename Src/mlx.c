/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:53:46 by lugoncal          #+#    #+#             */
/*   Updated: 2023/02/14 12:53:48 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init(t_data *data)
{
	data->mlx.mlx_ptr = mlx_init();
	if (!data->mlx.mlx_ptr)
		error_msg("Couldn't initialize mlx", data);
	data->mlx.win_ptr = mlx_new_window(data->mlx.mlx_ptr, data->comp * WSIZE, \
		data->alt * WSIZE, "./so_long");
	if (!data->mlx.win_ptr)
		error_msg("Couldn't open window", data);
}
