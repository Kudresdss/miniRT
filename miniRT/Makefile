# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 17:19:04 by cbridget          #+#    #+#              #
#    Updated: 2022/10/24 04:56:17 by ymirna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

HEAD = headers/minirt.h

SRC = main.c utilities/utilities.c utilities/hooks.c utilities/init.c raytracer/minirt.c \
raytracer/raytracer.c utilities/vectors.c raytracer/intersect_sphere.c \
raytracer/compute_lighting.c raytracer/intersect_plane.c raytracer/intersect_cylinder.c \
utilities/vectors_two.c utilities/utilities_two.c \
transform/transform.c transform/change_obj.c transform/ch_view.c transform/resize.c \
parcer/check_args.c parcer/check_params.c parcer/fill_info_1.c parcer/fill_info_2.c \
parcer/fill_info_3.c parcer/fill_valid.c parcer/init_info.c parcer/free.c parcer/parcer_basic_ft.c \
parcer/split.c parcer/get_next_line.c parcer/get_next_line_utils.c


OBJ = $(addprefix objects/,$(SRC:.c=.o))

BUILD_FOLDERS := $(shell mkdir -p objects; mkdir -p objects/raytracer; mkdir -p objects/utilities; mkdir -p objects/transform; mkdir -p objects/parcer)

FLAGS = -lm -Wall -Wextra
# FLAGS = -lm -Wall -Wextra -Werror -O3

CC = cc

.PHONY : all clean fclean bonus re LIB MINILIBX

all : LIB MINILIBX $(NAME)

MINILIBX :
	$(MAKE) -C mlx
#	$(MAKE) -C mlx_linux

LIB :
	$(MAKE) -C libft

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -Lmlx -lmlx -L/usr/lib -Llibft libft/libft.a -framework OpenGL -framework AppKit -o $(NAME)

objects/%.o : sources/%.c $(HEAD) Makefile libft/libft.a mlx/libmlx.a
	$(CC) $(FLAGS) -iquote headers -iquote libft -I/usr/include -c $< -o $@

# $(NAME) : $(OBJ)
# 	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lz -Llibft -lft $(FLAGS) -o $(NAME)

# objects/%.o : sources/%.c $(HEAD) Makefile libft/libft.a mlx_linux/libmlx.a
# 	$(CC) $(FLAGS) -iquote headers -iquote libft -I/usr/include -Imlx_linux -c $< -o $@

bonus : all

clean :
	rm -rf objects
	$(MAKE) clean -C libft
	$(MAKE) clean -C mlx
#	$(MAKE) clean -C mlx_linux

fclean :
	rm -rf objects
	rm -f $(NAME)
	$(MAKE) fclean -C libft
	$(MAKE) clean -C mlx
#	$(MAKE) clean -C mlx_linux

re :
	rm -r objects/*.o
	rm -f $(NAME)
	$(MAKE) fclean -C libft
	$(MAKE) clean -C mlx
#	$(MAKE) clean -C mlx_linux
	$(MAKE)
