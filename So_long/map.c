/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:49:25 by lugoncal          #+#    #+#             */
/*   Updated: 2023/05/17 18:48:31 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checkwall(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->length)
	{
		if (data->map[0][i] != '1' || data->map[data->width - 1][i] != '1')
			error_msg("Wall not valid!", data);
	}
	i = 0;
	while (++i < data->width - 1)
	{
		if (data->map[i][0] != '1' || data->map[i][data->length - 1] != '1')
			error_msg("Wall not valid!", data);
	}
}

void	checkchar(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->width)
	{
		j = -1;
		while (++j < data->length)
		{
			if (data->map[i][j] != '0' && data->map[i][j] != '1' &&
				data->map[i][j] != 'C' && data->map[i][j] != 'E' &&
				data->map[i][j] != 'P')
				error_msg("An element is missing on the map", data);
		}
	}
	getcoords(data);
	if (data->player != 1 || data->exit != 1 || data->coin == 0)
		error_msg("Too many elements or too few", data);
}

void	checkrectangle(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->width)
	{
		j = 0;
		while (data->map[i][j])
			j++;
		if (j == data->length)
			i++;
		else
			error_msg("This map is not a rectangle!", data);
	}
}

void	getmap(t_data *data, char *map)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(map, O_RDONLY);
	data->map = malloc(sizeof(char *) * (data->width + 1));
	i = -1;
	while (++i <= data->width)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		data->map[i] = ft_strtrim(line, "\n");
		free(line);
	}
	close(fd);
	checkrectangle(data);
	checkchar(data);
	checkwall(data);
}

void	getsize(t_data *data, char *map)
{
	int		fd;
	char	*tmp;
	int		i;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		error_msg("Couldn't open the file", data);
	i = 0;
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
		{
			free(tmp);
			break ;
		}
		if (data->length == 0)
			data->length = ft_strlen(tmp) - 1;
		i++;
		free(tmp);
	}
	data->width = i;
	close(fd);
}
