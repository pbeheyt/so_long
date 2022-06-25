# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 15:08:45 by pbeheyt           #+#    #+#              #
#    Updated: 2022/06/25 15:18:47 by pbeheyt          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRC		= main.c \
		check.c \
		check2.c \
		parsing.c \
		image.c \
		image_utilis.c \
		game.c \
		clear.c \

DIR 	= ${addprefix srcs/,${SRC}}

HEAD	= -I libft -I include -I mlx

CC 		= gcc

CFLAGS 	= -Wall -Wextra -Werror -g

OBJS 	= ${DIR:.c=.o}

LD_FLAG	= -L libft -L mlx

MLX_FLAG= -lm -lmlx -lXext -lX11

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	make -C mlx
	$(CC) $(CFLAGS) $(LD_FLAG) $(OBJS) -o $(NAME) -lft $(MLX_FLAG)


.c.o:
	${CC} ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}

clean:
	make clean -C libft
	make clean -C mlx
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft 
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re