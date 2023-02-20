/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:31:10 by lugoncal          #+#    #+#             */
/*   Updated: 2023/02/20 09:31:11 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	checkpath2(t_data *data, int i, int j)
{
	if (data->clone[i - 1][j] == 'F' || data->clone[i + 1][j] == 'F'\
	|| data->clone[i][j - 1] == 'F' || data->clone[i][j + 1] == 'F')
		return ;
	error_msg("Can't collect or get to the exit", data);
}

void	checkpath(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->alt)
	{
		j = 0;
		while (j < data->comp)
		{
			if (data->clone[i][j] == 'C')
				checkpath2(data, i, j);
			else if (data->lines[i][j] == 'E')
				checkpath2(data, i, j);
			j++;
		}
		i++;
	}
}

void	floodfill2(t_data *data, int y, int x)
{
	if (y < 0 || x < 0)
		return ;
	if (data->clone[y][x] == 'F' || data->clone[y][x] == '1')
		return ;
	if (data->clone[y][x] == 'C')
		data->clone[y][x] = 'C';
	else
		data->clone[y][x] = 'F';
	floodfill2(data, y + 1, x);
	floodfill2(data, y - 1, x);
	floodfill2(data, y, x -1);
	floodfill2(data, y, x + 1);
}

void	floodfill(t_data *data)
{
	int		i;

	data->clone = malloc(sizeof(char *) * data->alt);
	if (!data->clone)
		error_msg("Malloc error", data);
	i = 0;
	while (i < data->alt)
	{
		data->clone[i] = ft_strdup(data->lines[i]);
		i++;
	}
	floodfill2(data, data->itens.player_y, data->itens.player_x);
	checkpath(data);
}
