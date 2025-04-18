# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/16 15:45:47 by marvin            #+#    #+#              #
#    Updated: 2025/03/16 15:45:47 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME = phonebook

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =	Phonebook.cpp		\
		Phonebook_utils.cpp	\
        Contact.cpp			\
		main.cpp		


OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	echo "\033[32m$(NAME) compiled\033[0m"

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re