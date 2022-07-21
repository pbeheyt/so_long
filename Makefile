# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 15:08:45 by pbeheyt           #+#    #+#              #
#    Updated: 2022/07/21 06:11:59 by pbeheyt          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRC		= clear.c \
		game.c \
		game2.c \
		image.c \
		image2.c \
		main.c \
		map_parsing.c \
		map.c \
		map2.c \

SRC_BONUS	= clear_bonus.c \
			game_bonus.c \
			game2_bonus.c \
			image_bonus.c \
			image2_bonus.c \
			main_bonus.c \
			map_parsing_bonus.c \
			map_bonus.c \
			map2_bonus.c \

DIR 		= ${addprefix srcs/,${SRC}}

DIR_BONUS 	= ${addprefix srcs_bonus/,${SRC_BONUS}}

HEAD		= -I libft -I include -I mlx

CC 			= gcc

CFLAGS 		= -Wall -Wextra -Werror -g

OBJS 		= ${DIR:.c=.o}

OBJS_BONUS	= ${DIR_BONUS:.c=.o}

LD_FLAG		= -L libft -L mlx

MLX_FLAG	= -lm -lmlx -lXext -lX11

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	make -C mlx
	$(CC) $(CFLAGS) $(LD_FLAG) $(OBJS) -o $(NAME) -lft $(MLX_FLAG)

bonus: $(OBJS_BONUS)
	make -C libft
	make -C mlx
	$(CC) $(CFLAGS) $(LD_FLAG) $(OBJS_BONUS) -o $(NAME)_bonus -lft $(MLX_FLAG)

.c.o:
	${CC} ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}

clean:
	make clean -C libft
	make clean -C mlx
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	make fclean -C libft 
	rm -f $(NAME) $(NAME)_bonus

re: fclean all

.PHONY: all clean fclean re