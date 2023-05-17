/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:22:31 by lugoncal          #+#    #+#             */
/*   Updated: 2023/05/17 19:42:18 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	floodfill(t_data *data, char **dup, int x, int y)
{
	static int	c;
	static int	e;

	if (y < 0 || x < 0 || y > data->width || x > data->length
		|| dup[y][x] == '1' || dup[y][x] == 'F')
		return (0);
	else if (dup[y][x] == 'E')
	{	
		e++;
		dup[y][x] = 'F';
	}
	else if (dup[y][x] == 'C')
		c++;
	dup[y][x] = 'F';
	floodfill(data, dup, x + 1, y);
	floodfill(data, dup, x - 1, y);
	floodfill(data, dup, x, y + 1);
	floodfill(data, dup, x, y - 1);
	if (e == 1 && c == data->coin)
		return (1);
	return (0);
}

void	validmap(t_data *data)
{
	int		i;

	data->dup = malloc(sizeof(char *) * (data->width + 1));
	i = -1;
	while (++i < data->width)
		data->dup[i] = ft_strdup(data->map[i]);
	if (floodfill(data, data->dup, data->p.x, data->p.y) != 1)
		error_msg("Couldn't find a valide path", data);
	else
		freedup(data);
}
