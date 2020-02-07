# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/02 20:53:05 by ikrkharb          #+#    #+#              #
#    Updated: 2020/02/07 18:28:01 by ikrkharb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

FLAGS = -g -Wall -Werror -Wextra

SRCS = 	srcs/rtv1.c\
		srcs/data.c\
		srcs/manage.c\
		srcs/mlx_setup.c\
		srcs/mlx_hooks.c\
		srcs/init_scene.c\
		checker/checker.c\
		checker/check_keys.c\
		srcs/utils.c\

LIBFT = libft/libft.a

LIBPS = Dynamic_parser/libparser.a

INC = includes/rtv1.h

all: $(NAME)

$(NAME): $(SRCS) $(INC)
	@make -C libft > /dev/null
	@make -C Dynamic_parser > /dev/null
	@gcc $(FLAGS) -I usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework Appkit $(SRCS) $(LIBFT) $(LIBPS) -o $(NAME)
	@echo "\033[92mDone\033[0m"

clean:
	@make clean -C libft
	@make clean -C Dynamic_parser
	@echo "\033[92mCleaning done\033[0m"

fclean:
	@make fclean -C libft
	@make fclean -C Dynamic_parser
	@/bin/rm -rf $(NAME)
	@echo "\033[92mExecution and cleaning were done\033[0m"

re: fclean all