# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgallien <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/16 14:52:04 by hgallien          #+#    #+#              #
#    Updated: 2021/03/08 11:13:39 by hgallien         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/calcul.c srcs/calcul_utils.c srcs/collision.c srcs/collision_bis.c srcs/contour.c srcs/display.c srcs/display_obj.c srcs/display_utils.c srcs/display_utils_bis.c srcs/display_wall.c srcs/door.c srcs/draw.c srcs/explosion.c srcs/find_obj_utils.c srcs/find_obj_utils_2.c srcs/geofun.c srcs/geofun_bis.c srcs/get_info_utils.c srcs/get_map.c srcs/get_next_line.c srcs/get_next_line_utils.c srcs/gun.c srcs/hook.c srcs/hook_utils.c srcs/k_press.c srcs/k_press_b.c srcs/main.c srcs/load_img.c srcs/parse.c srcs/path.c srcs/bitmap.c  srcs/utils_g.c srcs/verif_map_utils.c srcs/free.c srcs/free_bis.c srcs/error_img.c srcs/free_tris.c srcs/error_info.c srcs/parse_utils.c srcs/main_utils.c srcs/verif_map_utils_bis.c srcs/get_first_line_utils.c
CC= gcc
CFLAGS= -Wall -Wextra -Werror
NAME= cub3D
VPATH= srcs
OBJ= $(SRCS:.c=.o)
DBGFLAGS= -g3 -fsanitize=address

.PHONY: clean fclean re all dgb

all: $(NAME) 

$(NAME): $(OBJ)
	$(CC)  $(OBJ) libmlx.dylib -o $(NAME)
dgb: $(OBJ)
	$(CC) $(DBGFLAGS) $(OBJ)  libmlx.dylib -o $(NAME)

%.o: %.c cub.h
	$(CC) $(CFLAGS) -c -o $@ $< 
clean:
	rm -f $(OBJ) $(SRCS:.c=.o)
fclean: clean
	rm -f $(NAME)
re: fclean all
