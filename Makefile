# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saalamoo <saalamoo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/19 15:44:47 by saalamoo          #+#    #+#              #
#    Updated: 2023/05/17 13:58:14 by saalamoo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3 -w

SRC =${wildcard libft/*.c} so_long.c maplines.c parsing.c player_mov.c img.c valid_map.c

RM = rm -f

all: $(NAME)

$(NAME): $(SRC)
	$(MAKE) all -C mlx
	$(CC) $(CFLAGS) $(SRC) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(MAKE) clean -C mlx

fclean: clean
	$(RM) $(NAME)
	$(MAKE) clean -C mlx

re: fclean $(NAME)

.PHONY = all clean fclean re