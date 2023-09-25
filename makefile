# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/14 10:12:00 by hatesfam          #+#    #+#              #
#    Updated: 2023/09/25 07:40:55 by hatesfam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# $(VERBOSE).SILENT:

NAME = philo

CC = cc
CFLAG = -Wall -Wextra -Werror
LINKER = -pthread
RM = rm -rf

SRC_FILES =  src/main.c src/check_args.c src/utils.c src/init.c\
			 src/case_one.c src/philo.c src/philo_actions.c src/philo_utils.c src/ft_clean.c
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