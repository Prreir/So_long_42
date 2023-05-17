/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:47:08 by lugoncal          #+#    #+#             */
/*   Updated: 2023/05/17 20:23:26 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroytextures(t_data *data)
{
	mlx_destroy_image(data->mlx.mlx_ptr, data->mlx.coin);
	mlx_destroy_image(data->mlx.mlx_ptr, data->mlx.exit);
	mlx_destroy_image(data->mlx.mlx_ptr, data->mlx.exit2);
	mlx_destroy_image(data->mlx.mlx_ptr, data->mlx.player);
	mlx_destroy_image(data->mlx.mlx_ptr, data->mlx.player2);
	mlx_destroy_image(data->mlx.mlx_ptr, data->mlx.player3);
	mlx_destroy_image(data->mlx.mlx_ptr, data->mlx.player4);
	mlx_destroy_image(data->mlx.mlx_ptr, data->mlx.wall);
	mlx_destroy_image(data->mlx.mlx_ptr, data->mlx.empty);
}

void    renderimg(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->width)
	{
		j = -1;
		while (++j < data->length)
		{
            if (data->map[i][j] == '1')
		        mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr, \
                data->mlx.wall, WSIZE * j, WSIZE * i);
	        else if (data->map[i][j] == '0')
		        mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr, \
                data->mlx.empty, WSIZE * j, WSIZE * i);
	        else if (data->map[i][j] == 'C')
	        	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr, \
                data->mlx.coin, WSIZE * j, WSIZE * i);
	        else if (data->map[i][j] == 'E')
        		mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr, \
                data->mlx.exit, WSIZE * j, WSIZE * i);
        	else if (data->map[i][j] == 'P')
        		mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr, \
        		data->mlx.player, WSIZE * j, WSIZE * i);
        }
	}
}

void    initmlx(t_data *data)
{
    data->mlx.mlx_ptr = mlx_init();
	if (!data->mlx.mlx_ptr)
		error_msg("Couldn't initialize mlx", data);
	data->mlx.win_ptr = mlx_new_window(data->mlx.mlx_ptr, data->length * WSIZE, \
		data->width * WSIZE, "./so_long");
	if (!data->mlx.win_ptr)
		error_msg("Couldn't open window", data);
}
