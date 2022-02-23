# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/18 23:05:35 by jeounpar          #+#    #+#              #
#    Updated: 2022/02/23 20:36:53 by jeounpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
MLX			= -O3 -L./minilibx -lmlx -framework OpenGL -framework Appkit
SRCS		= cli.c fractal_set.c draw_fractal.c key_hooks.c main.c utils.c
OBJECTS		= $(SRCS:.c=.o)
BONUS_SRCS	= cli_bonus.c fractal_set_bonus.c draw_fractal_bonus.c key_hooks_bonus.c main.c utils.c
OBJ_BONUS	= $(BONUS_SRCS:.c=.o)

ifdef WITH_BONUS
	OBJ_FILES = $(OBJ_BONUS)
else
	OBJ_FILES = $(OBJECTS)
endif

$(NAME)		: $(OBJ_FILES)
		make -C ./minilibx
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) $(MLX)

all			: $(NAME)

clean		:
		make -C ./minilibx clean
		rm -f $(OBJECTS) $(OBJ_BONUS)

fclean		: clean
		make -C ./minilibx fclean
		rm -f $(NAME)

bonus		:
		make WITH_BONUS=1 all

re			: fclean all