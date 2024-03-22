# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knarman <knarman@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/17 05:38:53 by knarman          #+#    #+#              #
#    Updated: 2024/03/22 02:00:52 by knarman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			=	so_long
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
AR				=	ar
ARFLAGS 		=	rcs
RM				=	rm -rf

SRC = src/main.c src/elements_control.c src/map_control_three.c src/game_start.c src/map_control_extra.c src/map_control.c src/read_map.c \
		src/walk.c src/utils.c src/utils2.c src/get_next_line/get_next_line.c src/get_next_line/get_next_line_utils.c

LIBRARY = -Lminilibx -lmlx -framework OpenGL -framework AppKit

MINILIBX_PATH	=	minilibx                               

all:				$(NAME)

$(NAME): mlx
					$(CC) $(CFLAGS) -o $(NAME) $(SRC) -framework OpenGL -framework AppKit -L$(MINILIBX_PATH) -lmlx


mlx:
					make -C $(MINILIBX_PATH) all

clean:
					$(RM) $(NAME)

fclean: clean
					make clean -C $(MINILIBX_PATH)
					
re:					fclean mlx all

.PHONY:				all clean fclean re bonus