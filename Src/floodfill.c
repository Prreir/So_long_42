/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:31:10 by lugoncal          #+#    #+#             */
/*   Updated: 2023/02/21 13:16:10 by marvin           ###   ########.fr       */
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

void	floodfill2(t_data *data, int i, int j)
{
	if (i < 0 || j < 0)
		return ;
	if (data->clone[i][j] == 'F' || data->clone[i][j] == '1')
		return ;
	if (data->clone[i][j] == 'C')
		data->clone[i][j] = 'C';
	else
		data->clone[i][j] = 'F';
	floodfill2(data, i + 1, j);
	floodfill2(data, i - 1, j);
	floodfill2(data, i, j -1);
	floodfill2(data, i, j + 1);
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
