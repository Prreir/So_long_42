/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:01:18 by marvin            #+#    #+#             */
/*   Updated: 2023/02/10 11:01:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft/libft.h"
# include "Libft/get_next_line.h"
# include "mlx/mlx.h"

# define WSIZE 64

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

typedef struct s_itens
{
	int		collec;
	int		exit;
	int		exit_x;
	int		exit_y;
	int		player;
	int		player_x;
	int		player_y;
}	t_itens;

typedef struct s_data
{
	int		comp;
	int		alt;
	char	**lines;
	t_itens	itens;
	t_mlx	mlx;
}	t_data;

//mlxutils.c
void	gameclose(t_data *data);
int		xbotton(void *data);

//mlx.c
void	init(t_data *data);

//checkmap.c
void	checkrectangle(int fd, char *tmp, t_data *data);
void	setposition(t_data *data, int i, int j);
void	checkchar(t_data *data);
void	checkwalls(t_data *data);
void	checkmap(t_data *data);

//getmap.c
void	savemap2(t_data *data, int fd);
void	savemap(t_data *data, char *map);
void	getsize(t_data *data, char *map);

//utils.c
void	iniciar(t_data *data);
void	error_msg(char *msg, t_data *data);
void	freemap(t_data *data);

//main.c
void	checkargs(int argc, char **argv, t_data *data);

#endif
