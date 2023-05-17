/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:11:16 by lugoncal          #+#    #+#             */
/*   Updated: 2023/05/17 21:08:13 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft/libft.h"
# include "Libft/get_next_line.h"
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"

# define WSIZE 64
# define COIN "Textures/Coin.xpm"
# define EXIT "Textures/Exit.xpm"
# define EXIT2 "Textures/Exit2.xpm"
# define PLAYER "Textures/Player.xpm"
# define PLAYER2 "Textures/Player2.xpm"
# define PLAYER3 "Textures/Player3.xpm"
# define PLAYER4 "Textures/Player4.xpm"
# define WALL "Textures/Wall.xpm"
# define EMPTY "Textures/Empty.xpm"

typedef struct s_mlx{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*coin;
	void	*exit;
	void	*exit2;
	void	*player;
	void	*player2;
	void	*player3;
	void	*player4;
	void	*wall;
	void	*empty;
}	t_mlx;

typedef struct s_pos{
	int		x;
	int		y;
}	t_pos;

typedef struct s_data{
	int		length;
	int		width;
	char	**map;
	char	**dup;
	int		coin;
	int		exit;
	int		player;
	int		mov;
	t_pos	p;
	t_pos	e;
	t_mlx	mlx;
}	t_data;

//upload.c
void	uploadmov(t_data *data, int mov);
void	uploadplayer(t_data *data, int i, int j, int p);
void	uploadimg(t_data *data, void *text, int i, int j);
int		uploadmap(t_data *data, int p);

//mlx.c
void	destroytextures(t_data *data);
void    renderimg(t_data *data);
void    initmlx(t_data *data);

//validmap.c
int		floodfill(t_data *data, char **dup, int x, int y);
void	validmap(t_data *data);

//get.c
int		getX(void *data);
void	playermove(t_data *data, int i, int j, int p);
int		getkeys(int	keycode, t_data *data);
void	getimg(t_data *data);
void	getcoords(t_data *data);

//map.c
void	checkwall(t_data *data);
void	checkchar(t_data *data);
void	checkrectangle(t_data *data);
void	getmap(t_data *data, char *map);
void	getsize(t_data *data, char *map);

//utils.c
void	killgame(t_data *data);
void	freedup(t_data *data);
void	freemap(t_data *data);
void	error_msg(char *str, t_data *data);

//main.c
void	checkarg(t_data *data, int argc, char *str);
void	init(t_data *data);

#endif