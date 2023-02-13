# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 21:52:21 by junyojeo          #+#    #+#              #
#    Updated: 2023/02/13 17:42:37 by junyojeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define the complier and flags

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -MMD -O2 -lmlx -framework OpenGl -framework AppKit
LIB				=	-L ./lib/libft/libft.a -lft -L ./lib/minilibx_mms_20191025_beta/mlx.a

# Define the directories

SRC_DIR			=	sources
BUILD_DIR		=	build
INC_DIR			=	-I includes

# Define the source files

CTRL_SRCS		=	$(addprefix ctrl_map/, ctrl_map.c)
DRAW_SRCS		=	$(addprefix draw_map/, draw_map.c)

FDF_SRCS		=	$(addprefix $(SRC_DIR)/, fdf.c $(CTRL_SRCS) $(DRAW_SRCS))
FDF_OBJS		=	$(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.d, $(FDF_SRC))
FDF_DEPS		=	$(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(FDF_SRC))


FDF		=	fdf

all:
		@$(MAKE) -j $(FDF)
	
# Define the target and dependencies

$(FDF): $(FDF_OBJS)
		@$(CC) $(CFLAGS) $^ -o $@
		@printf "${GREEN}> [FDF] success 🎉${END}"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | dir_guard
		@$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@

dir_guard:
		@mkdir -p $(BUILD_DIR)

clean:
		@$(RM) -r $(BUILD_DIR)
		@echo "${YELLOW}> All objects files of the FDF have been deleted.❌${END}"

fclean:
		@$(RM) -r $(FDF) $(BUILD_DIR) FDF
		@echo "${YELLOW}> Cleaning of the FDF has been done.❌${END}"

re: fclean
		@$(MAKE) all
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

-include $(FDF_DEPS)
