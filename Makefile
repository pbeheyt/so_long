# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 15:08:45 by pbeheyt           #+#    #+#              #
#    Updated: 2022/06/22 08:10:05 by pbeheyt          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRC		= main.c \
		# check.c \
		# parsing.c \
		# operations.c \
		# operations2.c \
		# sort_short_list.c \
		# sort_short_list2.c \
		# sort_long_list.c

DIR 	= ${addprefix srcs/,${SRC}}

HEAD	= -I libft -I include -I mlx

CC 		= gcc

CFLAGS 	= -Wall -Wextra -Werror -g

OBJS 	= ${DIR:.c=.o}

LD_FLAG	= -L libft

MLX_FLAG= -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	make -C mlx
	$(CC) $(CFLAGS) $(LD_FLAG) $(MLX_FLAG) $(OBJS) -o $(NAME) -lft 


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