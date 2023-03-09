# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 21:52:21 by junyojeo          #+#    #+#              #
#    Updated: 2023/03/09 20:25:37 by junyojeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define the complier and flags

NAME		=	fdf

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
CPPFLAGS	=	-I . -I mlx -I lib
LDLIBS		=	-lmlx -lft
LDFLAGS		=	-L. -Llib

SRC_DIR		=	src
BUILD_DIR	=	build

# Define the source files
SRCS		:=	$(addprefix $(SRC_DIR)/, init.c fdf.c)
SRCS		+=	$(addprefix $(SRC_DIR)/ctrl_map/, key_hook.c)
SRCS		+=	$(addprefix $(SRC_DIR)/draw_map/, draw_map.c)

OBJS		=	$(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/obj/%.o, $(SRCS))
DEPS		=	$(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/dep/%.d, $(SRCS))

all:	$(NAME)
	
# Define the target and dependencies

$(NAME): $(OBJS)
			@make -C lib
			@$(CC) $(CFLAGS) $(LDLIBS) $(LDFLAGS) $< -o $@
			@echo "${GREEN}> success 🎉${END}"

$(BUILD_DIR)/obj/%.o: $(SRC_DIR)/%.c
			@mkdir -p $(dir $@)
			@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

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
