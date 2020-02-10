# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/02 20:53:05 by ikrkharb          #+#    #+#              #
#    Updated: 2020/02/10 18:13:33 by ikrkharb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

FLAGS = -g -Wall -Werror -Wextra

SRCS = 	srcs/rtv1.c\
		srcs/data.c\
		srcs/manage.c\
		srcs/mlx_setup.c\
		srcs/mlx_hooks.c\
		srcs/init_env_values.c\
		checker/checker.c\
		checker/check_keys.c\
		srcs/utils.c\
		srcs/free.c\
		srcs/env_setup.c\
		DEBUG/debug_env.c\
		srcs/ray_gen.c\
		srcs/draw.c\
		srcs/math_ops.c\
		srcs/vec_scaling.c\
		srcs/intersections.c\

LIBFT = libft/libft.a

LIBPS = parser/libparser.a

INC = includes/rtv1.h

all: $(NAME)

$(NAME): $(SRCS) $(INC)
	@make -C libft > /dev/null
	@make -C parser > /dev/null
	@gcc $(FLAGS) -I usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework Appkit $(SRCS) $(LIBFT) $(LIBPS) -o $(NAME)
	@echo "\033[92mDone\033[0m"

clean:
	@make clean -C libft
	@make clean -C parser
	@echo "\033[92mCleaning done\033[0m"

fclean:
	@make fclean -C libft
	@make fclean -C parser
	@/bin/rm -rf $(NAME)
	@echo "\033[92mExecution and cleaning were done\033[0m"

re: fclean all