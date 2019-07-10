# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gly <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/02 09:45:18 by gly               #+#    #+#              #
#    Updated: 2019/07/09 14:32:42 by gly              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= lem-in
CC			= gcc
CFLAGS 		= -Wall -Wextra -Werror -g
INC_PATH	= \
	incl/ \
	libft/incl/

INC			= $(addprefix -I, $(INC_PATH))
OBJ_PATH	= obj/
OBJ			= $(addprefix $(OBJ_PATH), $(SRC:.c=.o))
SRC_PATH	= src/
LIBFT_PATH	= libft/
LIBFT		= $(addprefix $(LIBFT_PATH), libft.a)
LIBFT_FLAG	= -lft -L libft
RM			= /bin/rm -f
BUILD_PATH	= \
	$(SRC_SOLUTION_PATH) \
	$(SRC_INPUT_PATH) \
	$(SRC_ROOMLST_PATH) \
	$(SRC_MISC_PATH)

SRC			= \
	$(addprefix $(SRC_SOLUTION_PATH), $(SRC_SOLUTION)) \
	$(addprefix $(SRC_INPUT_PATH), $(SRC_INPUT)) \
	$(addprefix $(SRC_ROOMLST_PATH), $(SRC_ROOMLST)) \
	$(addprefix $(SRC_MISC_PATH), $(SRC_MISC))

SRC_SOLUTION_PATH = find_solution/
SRC_SOLUTION = \
	ft_adapt_glob_to_new_solution.c \
	ft_calculate_step.c \
	ft_explore_backward.c \
	ft_find_path.c \
	ft_find_solution.c \
	ft_get_path.c \
	ft_get_single_path.c \
	ft_get_new_path.c \
	ft_solution_manipulators.c \
	ft_pathlst_manipulators.c

SRC_INPUT_PATH = input_parsing/
SRC_INPUT = \
	ft_detect.c \
	ft_input.c \
	ft_input_parsing.c \
	ft_tools.c \
	ft_toolss.c

SRC_ROOMLST_PATH = roomlst/
SRC_ROOMLST = \
	ft_roomlst_add_push.c \
	ft_roomlst_del.c \
	ft_roomlst_init.c \
	ft_roomlst_new.c \
	ft_roomlst_pop_shift.c \
	ft_roomlst_tools.c

SRC_MISC_PATH = misc/
SRC_MISC = \
	ft_error.c \
	ft_global.c \
	ft_room.c \
	ft_option.c

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT_FLAG) -o $@ src/main_function/main.c \
		src/main_function/print_solution.c src/main_function/print_working_path.c \
		src/main_function/print_lem_in.c

$(LIBFT) :
	make -C libft

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	mkdir -p $(addprefix $(OBJ_PATH), $(BUILD_PATH))
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean :
	make -C libft clean
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME) $(LIBFT)

re : fclean all

.PHONY : all clean fclean re $(NAME)
