# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/18 23:05:35 by jeounpar          #+#    #+#              #
#    Updated: 2022/02/19 16:10:09 by jeounpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
MLX			= -O3 -L./minilibx -lmlx -framework OpenGL -framework Appkit
SRCS		= cli.c fractal_set.c draw_fractal.c key_hooks.c main.c utils.c
OBJECTS		= $(SRCS:.c=.o)

$(NAME)		: $(OBJECTS)
		make -C ./minilibx
		$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(MLX)

all			: $(NAME)

clean		:
		make -C ./minilibx clean
		rm -f $(OBJECTS)

fclean		: clean
		make -C ./minilibx fclean
		rm -f $(NAME)

bouse		:

re			: fclean all