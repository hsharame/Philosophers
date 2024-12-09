# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/24 13:28:28 by hsharame          #+#    #+#              #
#    Updated: 2024/12/09 11:53:30 by hsharame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo
SRCSDIR 	= sources/
SRCS_F		= main.c utils.c init.c routine.c check.c actions.c state.c
SRCS		= $(addprefix $(SRCSDIR), $(SRCS_F))
OBJS		= $(SRCS:.c=.o)
HEADER		= includes/philo.h
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -pthread
FLAG_DEBUG	= -fsanitize=thread
RM			= rm -f

all: $(NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "Creating the executable..."
	@echo "The program is ready. You can use './philo' for execute."

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I .

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.SILENT:
./PHONY: all clean fclean re