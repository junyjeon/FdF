# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junyojeo <junyojeo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 17:59:38 by junyojeo          #+#    #+#              #
#    Updated: 2023/05/19 01:59:12 by junyojeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libGNL.a

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

SRC			=	get_next_line.c get_next_line_utils.c
OBJ			=	$(SRC:.c=.o)

all :		$(NAME)

$(NAME) : mandatory

mandatory : $(NAME)($(OBJ))
clean : ; rm -f $(OBJ)
fclean : clean ; rm -f $(NAME)
re:	fclean all

.PHONY : all clean fclean re
