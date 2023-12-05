# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 23:35:16 by aschmitt          #+#    #+#              #
#    Updated: 2023/12/04 12:32:13 by aschmitt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			= push_swap

# Directories
INC				= inc/
SRC_DIR			= srcs/
OBJ_DIR			= obj/

# Compielr and Flags
CC				= cc
CFLAGS			= -Wall -Wextra -Werror -I
RM				= rm -f
AR				= ar rcs

# Source Files
SRC =	$(SRC_DIR)aux_stack.c  $(SRC_DIR)big_sort.c  $(SRC_DIR)find_target.c  $(SRC_DIR)little_sort.c $(SRC_DIR)ft_atoi.c $(SRC_DIR)ft_lst.c  $(SRC_DIR)ft_split.c  $(SRC_DIR)prepare_push_a.c \
		$(SRC_DIR)prepare_push_b.c  $(SRC_DIR)push.c  $(SRC_DIR)push_swap.c  $(SRC_DIR)reverse_rotate.c  $(SRC_DIR)rotate.c  $(SRC_DIR)swap.c


# Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
OBJ 			= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))
# Build rules
all: 			$(NAME)

$(NAME): 		$(OBJ)
				@$(CC) -o $(NAME) $(OBJ)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
				@$(RM) -r $(OBJ_DIR)

fclean: 		clean
				@$(RM) $(NAME)

re: 			fclean all

.PHONY: 		all clean fclean re
