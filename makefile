# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/14 10:12:00 by hatesfam          #+#    #+#              #
#    Updated: 2023/09/30 16:58:36 by hatesfam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# $(VERBOSE).SILENT:

NAME = philo

CC = cc
CFLAG = -Wall -Wextra -Werror
LINKER = -lpthread
RM = rm -rf

SRC_FILES =  src/main.c src/check_args.c src/utils.c src/init.c src/case_one.c\
			 src/routine.c src/philo_actions.c src/ft_clean.c src/fork_funcs.c
OBJ_FILES = ${SRC_FILES:.c=.o}

%.o : %.c
	cc $(CFLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAG) $^ $(LINKER) -o $@
	
clean:
	$(RM) $(OBJ_FILES)
	
fclean: clean
	$(RM) $(NAME)
	
re: fclean all

.PHONY: all clean fclean re