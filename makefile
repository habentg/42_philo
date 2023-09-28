<<<<<<< HEAD
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/14 10:12:00 by hatesfam          #+#    #+#              #
#    Updated: 2023/09/27 08:52:48 by hatesfam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# $(VERBOSE).SILENT:

NAME = philo

CC = cc
CFLAG = -Wall -Wextra -Werror -g3
LINKER = -pthread
CFLAG = -Wall -Wextra -Werror -g3
RM = rm -rf

SRC_FILES =  src/main.c src/check_args.c src/utils.c src/init.c src/case_one.c\
			 src/routine.c src/philo_actions.c src/philo_utils.c src/ft_clean.c src/fork_funcs.c
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

=======
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/14 10:12:00 by hatesfam          #+#    #+#              #
#    Updated: 2023/09/25 05:03:14 by hatesfam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# $(VERBOSE).SILENT:

NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
LINKER = -pthread
RM = rm -rf

SRC_FILES =  src/main.c src/check_args.c src/utils.c src/init.c\
			 src/case_one.c src/philo.c src/philo_actions.c src/philo_utils.c
OBJ_FILES = ${SRC_FILES:.c=.o}

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ $(LINKER) -o $@
	
clean:
	$(RM) $(OBJ_FILES)
	
fclean: clean
	$(RM) $(NAME)
	
re: fclean all

>>>>>>> 977dedb415dbf604b57a6a13760b89c67a54998f
.PHONY: all clean fclean re