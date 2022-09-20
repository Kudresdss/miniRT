# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/30 13:49:23 by ymirna            #+#    #+#              #
#    Updated: 2022/09/20 23:30:25 by ymirna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	miniRT

PATH_M		=	mandatory/

PATH_B		=	bonus/

PATH_H		=	headers/

SRC_M		=	main.c check_arg.c fill_info_1.c fill_info_2.c basic_ft.c free.c \
					get_next_line.c get_next_line_utils.c

SRC_B		= 	bonus.c

HEADER		=	mini_rt.h get_next_line.h

SRC_M_P		=	$(addprefix $(PATH_M), $(SRC_M))

SRC_B_P		=	$(addprefix $(PATH_B), $(SRC_B))

HEADER_P	=	$(addprefix $(PATH_H), $(HEADER))

OBJS_M		=	$(SRC_M_P:%.c=%.o)

OBJS_B		=	$(SRC_B_P:%.c=%.o)

CC			=	cc

FLAGS		=	-Wall -Werror -Wextra

.PHONY:		all bonus re clean fclean

%.o : %.c	$(HEADER_P)
			$(CC) $(FLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS_M) Makefile
			$(CC) $(FLAGS) $(OBJS_M) -o $(NAME)

bonus:		
			@make OBJS_M="$(OBJS_B)" all
 
clean:		
			rm -f $(OBJS_M)
			rm -f $(OBJS_B)

fclean:		clean
			rm -f $(NAME)

re:			fclean all