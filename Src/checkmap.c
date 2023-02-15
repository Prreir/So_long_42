/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 09:38:56 by marvin            #+#    #+#             */
/*   Updated: 2023/02/11 09:38:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	checkrectangle(int fd, char *tmp, t_data *data)
{
	if (data->comp != 0 && data->comp != ((int)ft_strlen(tmp) - 1))
	{
		free(tmp);
		close(fd);
		error_msg("Map is not a rectangle", data);
	}
}

void	checkmap(t_data *data)
{
	int		i;
	int		j;

	checkwalls(data);
	i = 0;
	while (i < data->alt)
	{
		j = 0;
		while (j < data->comp)
		{
			if (ft_strchr("01CEP", data->lines[i][j]) == NULL)
				error_msg("Elements that are not (01CEP)", data);
			j++;
		}
		i++;
	}
	checkchar(data);
	if (data->itens.player != 1 || data->itens.exit != 1 \
	|| data->itens.collec == 0)
		error_msg("Missing elements (01CEP)", data);
}

void	checkwalls(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->alt)
	{
		if (y == 0 || y == data->alt - 1)
		{
			x = 0;
			while (x < data->comp)
			{
				if (data->lines[y][x] != '1')
					error_msg("Map has invalid walls", data);
				x++;
			}
		}
		else
		{
			if (data->lines[y][0] != '1' && \
			data->lines[y][data->comp - 1] != '1')
				error_msg("Map has invalid walls", data);
		}
		y++;
	}
}

void	checkchar(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->alt)
	{
		j = -1;
		while (++j < data->comp)
		{
			if (data->lines[i][j] == 'C')
				data->itens.collec++;
			else if (data->lines[i][j] == 'P')
			{
				data->itens.player++;
				setposition(data, i, j);
			}
			else if (data->lines[i][j] == 'E')
			{
				data->itens.exit++;
				setposition(data, i, j);
			}
		}
	}
}

void	setposition(t_data *data, int i, int j)
{
	if (data->lines[i][j] == 'E')
	{
		data->itens.exit_x = j;
		data->itens.exit_y = i;
	}
	if (data->lines[i][j] == 'P')
	{
		data->itens.player_x = j;
		data->itens.player_y = i;
	}
}
