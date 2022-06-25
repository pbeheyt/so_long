/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 04:41:55 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/06/25 07:13:58 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "mlx.h"
# include "libft.h"

typedef struct s_size
{
	int		height;
	int		width;
}			t_size;

typedef struct s_pos
{
	int		x;
	int		y;
}			t_pos;

typedef struct s_map
{
	char	*name;
	char 	**tab;
	t_size	size;
	t_pos	player_pos;
	t_pos	delta;
	int		width;
	int		collectible_count;
	int		move_count;
}			t_map;

typedef struct s_sprite
{
	void	*content;
	char	*path;
	char	c;
	struct s_sprite	*next;
	t_size	size;

}			t_sprite;

typedef struct s_image
{
	void		*mlx;
	void		*win;
	t_sprite	*list;
	t_sprite	*empty;
	t_sprite	*wall;
	t_sprite	*collectible;
	t_sprite	*exit;
	t_sprite	*player;
}				t_image;

typedef struct s_data
{
	int		error;
	t_map	*map;
	t_image	*image;
}			t_data;

enum e_dir
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
};

/*parsing.c*/
char	*put_map_into_str(t_data *data);
char	**parse_map_into_table(t_data *data);
void	free_tab(char **tab);

/*check.c*/
int		check_map(t_data *data);
void	check_map_dimensions(t_data *data);
int		check_horizontal_wall(char *row);
void	check_walls(t_data *data);

/*check2.c*/
int		is_content(char c, int *exit_count, int *player_count, t_data *data);
void	check_content(t_data *data);

/*image.c*/
t_sprite	*init_sprite(t_data *data, char *path, char c);
void		load_sprites(t_data *data);
void		*find_content(t_image *image, char c);
void		load_map(t_data *data);

/*image_utilis.c*/
void		list_add_back(t_sprite **lst, t_sprite *new);
t_sprite	*get_list_last(t_sprite *lst);

/*game.c*/
int		keyboard_input(int keycode, t_data *data);
t_pos	find_player_position(t_data *data);
void move_player_dir(t_data *data, int dir);
void move_player(t_data *data, t_pos delta);

#endif