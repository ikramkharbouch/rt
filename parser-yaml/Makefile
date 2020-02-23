# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/04 21:43:33 by ikrkharb          #+#    #+#              #
#    Updated: 2020/02/23 19:19:42 by ikrkharb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libparser.a

FLAGS = -g -Wall -Wextra -Werror

SRC = 	parser.c\
		utils.c\
		ft_lst_ops.c\
		new_list.c\

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