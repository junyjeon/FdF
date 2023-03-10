# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 21:52:21 by junyojeo          #+#    #+#              #
#    Updated: 2023/03/10 16:31:17 by junyojeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define the complier and flags

NAME		=	fdf

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
CPPFLAGS	=	-I . -I mlx -I lib

LIBFT_DIR	=	./libft
LIBFT		=	$(LIBFT_DIR)/libft.a

MLX_DIR		=	./mlx
MLX			=	$(MLX_DIR)/libmlx.a

SRC_DIR		=	src
BUILD_DIR	=	build

# Define the source files
SRC			=	$(addprefix $(SRC_DIR)/, init.c fdf.c key_hook.c draw_map.c)
OBJ			=	$(SRC:.c=.o)

# OBJ		=	$(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/obj/%.o, $(SRC))
# DEP		=	$(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/dep/%.d, $(SRC))

all:	$(NAME)
	
$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $@ $(OBJ) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(MLX_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean alln re
