# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 21:52:21 by junyojeo          #+#    #+#              #
#    Updated: 2023/03/23 03:09:37 by junyojeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define the complier and flags

NAME		=	fdf

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g3
CFLAGS		+=	-fsanitize=address

LIBFT_DIR	=	./lib/libft
LIBFT		=	$(LIBFT_DIR)/libft.a

GNL_DIR		=	./lib/get_next_line
GNL			=	$(GNL_DIR)/libGNL.a

MLX_DIR		=	./lib/mlx
MLX			=	$(MLX_DIR)/libmlx.dylib

CPPFLAGS	=	-I. -I$(GNL_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)
LDFLAGS		=	-L$(LIBFT_DIR) -lft -L$(GNL_DIR) -lGNL -L$(MLX_DIR) -lmlx

SRC_DIR		=	src
BUILD_DIR	=	build

SRC			=	$(addprefix $(SRC_DIR)/, fdf.c init.c parse.c draw.c algorithm.c key_hook.c utils.c utils2.c)
OBJ			=	$(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))

all:	$(NAME)

$(NAME): $(OBJ) $(LIBFT) $(GNL) $(MLX)
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS) -framework Metal -framework MetalKit -framework QuartzCore
	@echo "$(GREEN)SUCCESS$(END)"

$(LIBFT):
	@make -C $(LIBFT_DIR) bonus

$(GNL):
	@make -C $(GNL_DIR)

$(MLX):
	@make -C $(MLX_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | mkdir
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

mkdir:
	@mkdir -p $(BUILD_DIR)

clean:
	@$(RM) -r $(BUILD_DIR)

fclean: clean
	@$(RM) -r $(NAME) $(LIBFT) $(GNL) $(MLX) $(BUILD_DIR) fdf

re: fclean
	@$(MAKE)

GREEN			=	$'\x1b[32m
YELLOW			=	$'\x1b[33m

.PHONY: all mkdir clean fclean re
