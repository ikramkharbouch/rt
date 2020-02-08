# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/04 21:43:33 by ikrkharb          #+#    #+#              #
#    Updated: 2020/02/08 16:30:01 by ikrkharb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libparser.a

FLAGS = -Wall -Wextra -Werror

SRC = 	parser.c\
		utils.c

OBJ = $(SRC:.c=.o)

INC = parser.h

$(NAME): $(OBJ) $(INC)
	@gcc $(FLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

all: $(NAME)

clean:
	@/bin/rm -rf $(OBJ)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all
