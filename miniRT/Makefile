# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 17:19:04 by cbridget          #+#    #+#              #
#    Updated: 2022/10/20 03:58:11 by ymirna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

HEAD = headers/minirt.h

SRC = main.c check_args.c check_params.c fill_info_1.c fill_info_2.c fill_valid.c \
		get_next_line.c get_next_line_utils.c parcer_basic_ft.c split.c \
		free.c init.c init_info.c

OBJ = $(addprefix objects/,$(SRC:.c=.o))

BUILD_FOLDER := $(shell mkdir -p objects)

FLAGS = -lm -Imlx -Wall -Wextra #-Werror -O3

# FLAGS = -lm -Wall -Wextra #-Werror -O3

CC = cc

.PHONY : all clean fclean bonus re LIB MINILIBX

all : LIB MINILIBX $(NAME)

MINILIBX :
	$(MAKE) -C mlx

LIB :
	$(MAKE) bonus -C libft

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -Lmlx -lmlx -L/usr/lib -Llibft libft/libft.a -framework OpenGL -framework AppKit -o $(NAME)

objects/%.o : sources/%.c $(HEAD) Makefile libft/libft.a mlx/libmlx.a
	$(CC) $(FLAGS) -iquote headers -iquote libft -I/usr/include -c $< -o $@

# $(NAME) : $(OBJ)
# 	$(CC) $(FLAGS) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -Llibft libft/libft.a -o $(NAME)

# objects/%.o : sources/%.c $(HEAD) Makefile libft/libft.a mlx_linux/libmlx.a
# 	$(CC) $(FLAGS) -iquote headers -iquote libft -I/usr/include -Imlx_linux -c $< -o $@

bonus : all

clean :
	rm -rf objects
	$(MAKE) clean -C libft

fclean :
	rm -rf objects
	rm -f $(NAME)
	$(MAKE) fclean -C libft

re :
	rm -r objects/*.o
	rm -f $(NAME)
	$(MAKE) fclean -C libft
	$(MAKE)
