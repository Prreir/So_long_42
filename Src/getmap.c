/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:24:04 by lugoncal          #+#    #+#             */
/*   Updated: 2023/02/14 11:24:05 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	getsize(t_data *data, char *map)
{
	int		fd;
	int		i;
	char	*tmp;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		error_msg("File reading", data);
	i = 0;
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
		{
			free(tmp);
			break ;
		}
		if (data->comp == 0)
			data->comp = ft_strlen(tmp) - 1;
		checkrectangle(fd, tmp, data);
		i++;
		free(tmp);
	}
	close(fd);
	data->alt = i;
}

void	savemap(t_data *data, char *map)
{
	int		fd;

	fd = open(map, O_RDONLY);
	data->lines = malloc(sizeof(char *) * (data->alt));
	if (!data->lines)
	{
		close(fd);
		error_msg("Memory alloc", data);
	}
	savemap2(data, fd);
	close(fd);
}

void	savemap2(t_data *data, int fd)
{
	int		x;
	int		y;
	char	*line;

	y = 0;
	while (y < data->alt)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			data->alt = y;
			error_msg("In memory", data);
		}
		data->lines[y] = malloc(data->comp + 1);
		x = -1;
		while (++x < data->comp)
			data->lines[y][x] = line[x];
		data->lines[y][data->comp] = '\0';
		free(line);
		y++;
	}
	line = get_next_line(fd);
	free(line);
}
