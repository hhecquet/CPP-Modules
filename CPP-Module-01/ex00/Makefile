# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/16 15:45:47 by marvin            #+#    #+#              #
#    Updated: 2025/04/22 11:10:00 by hhecquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME = ex00

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp		\
		newZombie.cpp	\
		randomChump.cpp	\
		Zombie.cpp	


OBJDIR = 🖇️​
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	echo "\033[32m$(NAME) compiled 🧩\033[0m"

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re