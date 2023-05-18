# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junyojeo <junyojeo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 21:52:21 by junyojeo          #+#    #+#              #
#    Updated: 2023/05/19 02:12:54 by junyojeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror# -g2
# CFLAGS		+=	-fsanitize=address

LIBFT_DIR	=	./lib/libft
LIBFT		=	$(LIBFT_DIR)/libft.a

GNL_DIR		=	./lib/get_next_line
GNL			=	$(GNL_DIR)/libGNL.a

MLX_DIR		=	./lib/mlx
MLX			=	$(MLX_DIR)/libmlx.dylib

CPPFLAGS	=	-I. -I$(GNL_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)
LDFLAGS		=	-L$(LIBFT_DIR) -lft -L$(GNL_DIR) -lGNL -L$(MLX_DIR) -lmlx

BUILD_DIR	=	build

SRC			=	main.c init.c parse.c draw.c algorithm.c hook.c moving_hook.c utils.c utils2.c
B_SRC		=	main_bonus.c init_bonus.c parse_bonus.c draw_bonus.c algorithm_bonus.c hook_bonus.c moving_hook_bonus.c utils_bonus.c utils2_bonus.c
OBJ			=	$(SRC:.c=.o)
B_OBJ		=	$(B_SRC:.c=.o)

ifdef WITH_BONUS
        OBJ_FILE = $(B_OBJ)
else
        OBJ_FILE = $(OBJ)
endif

all:	$(NAME)

$(NAME): $(OBJ_FILE)
	@make -C $(MLX_DIR)
	@make -C $(LIBFT_DIR)
	@make -C $(GNL_DIR)
	@cp $(MLX) .
	@$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) -framework Metal -framework MetalKit -framework QuartzCore
	@echo "$(GREEN)SUCCESS$(END)"

$(LIBFT):
	@make -C $(LIBFT_DIR) bonus

$(GNL):
	@make -C $(GNL_DIR)

$(MLX):
	@make -C $(MLX_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

bonus:
	@make WITH_BONUS=1 all

clean:
	@$(RM) -r $(OBJ) $(B_OBJ)

fclean:
	make clean
	@$(RM) -r $(NAME) $(LIBFT) $(GNL) $(MLX) libmlx.dylib

re: fclean all

GREEN		=	$'\x1b[32m
YELLOW		=	$'\x1b[33m

.PHONY: all mkdir clean fclean re
