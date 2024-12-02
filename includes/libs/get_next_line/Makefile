# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/17 16:50:23 by ncampbel          #+#    #+#              #
#    Updated: 2024/11/17 19:26:18 by ncampbel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= get_next_line.a
CC= cc
CFLAGS= -Wall -Wextra -Werror
SRC= get_next_line.c \
		get_next_line_utils.c
OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -crs $(NAME) $(OBJ)


clean:
	rm -f $(OBJ)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re