# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 21:52:21 by junyojeo          #+#    #+#              #
#    Updated: 2023/03/03 19:57:05 by junyojeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define the complier and flags

NAME		=	fdf

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
MLX_FLAG	=	-L./lib/mlx -framework OpenGL -framework Appkit

HEADERS		=	-I ./include

# Define the source files

CTRL_SRCS	=	$(addprefix ctrl_map/, key_hook.c)
DRAW_SRCS	=	$(addprefix draw_map/, draw_map.c)

SRCS		=	$(addprefix src/, fdf.c init.c $(DRAW_SRCS))
OBJS		=	$(patsubst build/%.c, $(BUILD_DIR)/%.o, $(SRCS))
DEPS		=	$(patsubst build/%.c, $(BUILD_DIR)/%.d, $(SRCS))

all:	$(NAME)
	
# Define the target and dependencies

$(NAME): $(OBJS)
			$(CC) $(CFLAGS) $(HEADERS) $(MLX_FLAG) $< -o $@
			@printf "${GREEN}> [FDF] success 🎉${END}"

$(BUILD_DIR)/%.o: build/%.c | dir_guard
			$(CC) $(CFLAGS) $(MLX_FLAG) -c $< -o $@

dir_guard:
			mkdir -p $(addprefix $(BUILD_DIR)/, ctrl_map)
			mkdir -p $(addprefix $(BUILD_DIR)/, draw_map)

clean:
			$(RM) -r $(BUILD_DIR)
			@echo "${YELLOW}> All objects files of the FDF have been deleted.❌${END}"

fclean: clean
			$(RM) -f $(NAME) $(BUILD_DIR) FDF
			@echo "${YELLOW}> Cleaning of the FDF has been done.❌${END}"

re: fclean
			$(MAKE) all
			@printf "$(GREEN)Cleaned and rebuilt everything for FDF!${END}"

.PHONY:	all clean fclean re dir_guard

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
