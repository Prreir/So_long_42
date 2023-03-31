# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 10:57:52 by marvin            #+#    #+#              #
#    Updated: 2023/02/10 10:57:52 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./Libft/libft.a
MLX = -L ./mlx -lmlx -Ilmlx -lXext -lX11

SRC = ./Src/main.c ./Src/utils.c ./Src/getmap.c ./Src/checkmap.c ./Src/mlx.c \
	./Src/textures.c ./Src/hooks.c ./Src/uploadmap.c ./Src/floodfill.c

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