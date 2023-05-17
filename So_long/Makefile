# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 16:14:58 by lugoncal          #+#    #+#              #
#    Updated: 2023/05/17 21:01:56 by lugoncal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./Libft/libft.a
MLX = -L ./mlx -lmlx -Ilmlx -lXext -lX11

SRC = main.c utils.c map.c get.c validmap.c mlx.c upload.c

OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(LIBFT):
		$(MAKE) -C ./Libft

$(NAME):	$(OBJ) $(LIBFT)
		$(MAKE) -C ./mlx
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -o so_long
		

clean:
	$(MAKE) clean -C ./Libft
	rm -rf $(OBJ)

fclean: clean
	$(MAKE) fclean -C ./Libft
	rm -rf $(NAME)

re:	fclean all