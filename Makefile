# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 21:52:21 by junyojeo          #+#    #+#              #
#    Updated: 2023/03/12 16:14:03 by junyojeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define the complier and flags

NAME		=	fdf

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

LIBFT_DIR	=	./libft
LIBFT		=	$(LIBFT_DIR)/libft.a

GNL_DIR		=	./get_next_line
GNL			=	$(GNL_DIR)/get_next_line.a

MLX_DIR		=	./mlx
MLX			=	$(MLX_DIR)/libmlx.dylib

SRC_DIR		=	src
BUILD_DIR	=	build

# Define the source files
SRC			=	$(addprefix $(SRC_DIR)/, fdf.c init.c parse_map.c draw_map.c key_hook.c)
OBJ			=	$(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))

# OBJ		=	$(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/obj/%.o, $(SRC))
# DEP		=	$(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/dep/%.d, $(SRC))

all:	
	@$(MAKE) -j $(NAME)
	
$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(CPPFLAGS) -L$(LIBFT_DIR) -lft -L$(GNL_DIR)\
	 -lgnl -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(MLX):
	@make -C $(MLX_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | mkdir
	$(CC) $(CFLAGS) -I. -I$(GNL_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR) -c $< -o $@

mkdir:
	@mkdir -p $(BUILD_DIR)
	
clean:
	@$(RM) -r $(BUILD_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(GNL_DIR) clean
	@make -C $(MLX_DIR) clean

fclean: clean
	@$(RM) -r $(NAME) $(BUILD_DIR) fdf
	@make -C $(LIBFT_DIR) fclean
	@make -C $(GNL_DIR) fclean
	@make -C $(MLX_DIR) fclean

re: fclean
	@$(MAKE)

.PHONY: all mkdir clean fclean re
