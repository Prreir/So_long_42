/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:30:04 by lugoncal          #+#    #+#             */
/*   Updated: 2023/05/17 20:27:57 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	killgame(t_data *data)
{
	destroytextures(data);
	mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.win_ptr);
	mlx_destroy_display(data->mlx.mlx_ptr);
	free(data->mlx.mlx_ptr);
	freemap(data);
	exit(0);
}

void	freedup(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->width)
	{
		free(data->dup[i]);
		i++;
	}
	free(data->dup);
}

void	freemap(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->width)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}

void	error_msg(char *str, t_data *data)
{
	ft_putstr_fd("Error: ", 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
	if (data->map)
		freemap(data);
	if (data->dup)
		freedup(data);
	exit(1);
}
