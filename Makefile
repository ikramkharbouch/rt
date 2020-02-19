# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/02 20:53:05 by ikrkharb          #+#    #+#              #
#    Updated: 2020/02/19 23:20:38 by ikrkharb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

FLAGS = -g -Wall -Werror -Wextra

SRCS = 	srcs/ray_gen.c\
		srcs/fill_data.c\
		srcs/hooks.c\
		srcs/parsing.c\
		srcs/rtv1.c\
		srcs/vectors_ops.c\
		DEBUG/debug.c\
		srcs/objects.c\
		srcs/intersection.c\
		srcs/utils.c \
		srcs/color.c\
		srcs/phong_model.c\
		checker/checker.c\
		checker/check_keys.c\
		checker/checker_utils.c\
		srcs/transform.c\
		srcs/init_env.c\
		srcs/mlx.c\
		srcs/parsing_utils.c\
		srcs/rotate_axes.c\
		srcs/vec_scaling.c\

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