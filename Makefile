# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 21:52:21 by junyojeo          #+#    #+#              #
#    Updated: 2023/01/05 17:48:14 by junyojeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Game
CFLAGS		=	-Wall -Wextra -Werror -Wunreachable-code -0fast
LIBMLX		=	./lib/MLX42

HEADERS		=	-I ./include -I $(LIBMLX)/include
LIBS		=	$(LIBMLX)/libmlx42.a -ldl -lglfw -pthread -lm
SRCS		=	$(shell find ./src -iname "*.c")
OBJS		=	$(SRCS:.c=.o)
CC			=	cc

.INTERMEDIATE : $(SRCS:.c=.o)
.PHONY : all, clean, fclean, re, libmlx

all :	libmlx $(NAME)

libmlx:
		@$(MAKE) -C $(LIBMLX)

%.o: %.c
		@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)" 

$(NAME) : $(OBJS)
		@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
	
clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBMLX) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBMLX) fclean

re: clean all
