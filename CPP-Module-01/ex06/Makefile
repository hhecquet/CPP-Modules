# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/29 15:24:57 by marvin            #+#    #+#              #
#    Updated: 2025/05/08 08:59:31 by hhecquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME = harlfilter

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

SRCS =	main.cpp		\
		Harl.cpp


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