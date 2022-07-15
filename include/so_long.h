/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 04:41:55 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/07/15 06:08:51 by pbeheyt          ###   ########.fr       */
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

# define TILE_SIZE 128
# define IMAGE_COUNT 15
# define INT_DELAY 20000

typedef struct s_size
{
	int				height;
	int				width;
}					t_size;

typedef struct s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct s_map
{
	int				error;
	char			*name;
	char			**tab;
	t_size			size;
	t_pos			player_pos;
	t_pos			delta;
	int				width;
	int				collectible_count;
	int				move_count;
}					t_map;

typedef struct s_sprite
{
	void			*content;
	char			*path;
	char			c;
	char			behavior;
	t_size			size;
	struct s_sprite	*next;
}					t_sprite;

typedef struct s_image
{
	void			*mlx;
	void			*win;
	t_sprite		*list;
	char			exit_behavior;
	char			player_behavior;
	char			wall_behavior;
	int				sprites_loaded;
	int				map_delay;
	int				map_first_load;
	int				end_game;
}					t_image;

typedef struct s_data
{
	t_map			*map;
	t_image			*image;
}					t_data;

enum e_dir
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
};

/*parsing.c*/
char		*put_map_into_str(int fd);
char		**parse_map_into_table(t_map *map);

/*check.c*/
int			check_map(t_map *map);
void		check_map_dimensions(t_map *map);
int			check_horizontal_wall(char *row);
void		check_walls(t_map *map);

/*check2.c*/
int			is_content(char c, int *exit_count, int *player_count, t_map *map);
void		check_content(t_map *map);

/*image.c*/
void		init_mlx(t_map *map, t_image *image, t_data *data);
void		init_sprites(t_image *image, t_data *data);
void		*find_content(t_image *image, char c);
int			load_map(t_data *data);
int			load_animated_walls(t_data *data);
void 		display_text(t_map *map, t_image *image);

/*image_utilis.c*/
void		list_add_back(t_sprite **lst, t_sprite *new);
t_sprite	*get_list_last(t_sprite *lst);

/*game.c*/
int			keyboard_input(int keycode, t_data *data);
t_pos		find_player_position(t_map *map);
void		move_player_dir(t_map *map, t_image *image, t_data *data, int dir);
void		move_player(t_map *map, t_image *image, t_data *data, t_pos delta);

/*clear.c*/
int			clear_all(t_data *data);
void		free_tab(char **tab);
void		clear_mlx(t_image *image);

#endif