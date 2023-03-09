# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 21:52:21 by junyojeo          #+#    #+#              #
#    Updated: 2023/03/09 10:52:41 by junyojeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define the complier and flags

NAME		=	fdf

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
MAC_MLX_FLAG=	-framework OpenGL -framework Appkit
MMS_MLX_FLAG=	-

LIB_DIR		=	./lib
INC_DIR		=	inc
SRC_DIR		=	src
BUILD_DIR	=	build

MLX_DIR		=	./mlx
MLX			=	$(addprefix $(MLX_DIR)/, libmlx.a)

# Define the source files
CTRL_SRCS	=	$(addprefix ctrl_map/, key_hook.c)
DRAW_SRCS	=	$(addprefix draw_map/, draw_map.c)

SRCS_TOTAL	=	fdf.c init.c $(CTRL_SRCS) $(DRAW_SRCS)
SRCS		=	$(addprefix $(SRC_DIR)/, $(SRCS_TOTAL))
OBJS		=	$(patsubst %.c, $(BUILD_DIR)/%.o, $(SRCS_TOTAL))
DEPS		=	$(patsubst %.c, $(BUILD_DIR)/%.d, $(SRCS_TOTAL))

all:	$(NAME)
	
# Define the target and dependencies
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -Lmlx_mms -lmlx $(MAC_MLX_FLAG) -o $@
	@echo "${GREEN}> success 🎉${END}"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -lmlx -c $< -o $@

clean:
	@$(RM) -r $(BUILD_DIR)

fclean: clean
	@$(RM) -f $(NAME) $(BUILD_DIR) FDF
	@echo "${YELLOW}> Cleaning ${END}"

re: fclean
	@make all

.PHONY:	all clean fclean re

#Colors
END				=	$'\x1b[0m
BOLD			=	$'\x1b[1m
UNDER			=	$'\x1b[4m
REV				=	$'\x1b[7m
GREY			=	$'\x1b[30m
RED				=	$'\x1b[31m
GREEN			=	$'\x1b[32m
YELLOW			=	$'\x1b[33m
BLUE			=	$'\x1b[34m
PURPLE			=	$'\x1b[35m
CYAN			=	$'\x1b[36m
WHITE			=	$'\x1b[37m

-include $(DEPS)