/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:56:10 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/07/15 06:31:32 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**pathes(void)
{
	static char	*pathes[IMAGE_COUNT] = {
		"image/0S.xpm",
		"image/10.xpm",
		"image/11.xpm",
		"image/12.xpm",
		"image/13.xpm",
		"image/CS.xpm",
		"image/EE.xpm",
		"image/ES.xpm",
		"image/OS.xpm",
		"image/PK.xpm",
		"image/PD.xpm",
		"image/PL.xpm",
		"image/PR.xpm",
		"image/PS.xpm",
		"image/PU.xpm",
	};

	return (pathes);
}

void	init_sprites(t_image *image, t_data *data)
{
	t_sprite	*sprite;
	char 		**tab;
	int 		i;

	image->list = NULL;
	tab = pathes();
	i = -1;
	while (++i < IMAGE_COUNT)
	{
		sprite = malloc(sizeof(t_sprite));
		if (!sprite)
		{
			ft_putstr_fd("Error\nMemory allocation failed\n", 2);
			clear_all(data);
		}
		sprite->path = tab[i];
		sprite->c = tab[i][6];
		sprite->behavior = tab[i][7];
		sprite->next = NULL;
		sprite->content = mlx_xpm_file_to_image(image->mlx, sprite->path,
			&sprite->size.width, &sprite->size.height);
		list_add_back(&image->list, sprite);
	}
}

void 	display_text(t_map *map, t_image *image)
{
	t_pos	player_pos;
	
	player_pos = find_player_position(map);
	mlx_string_put(image->mlx, image->win, TILE_SIZE / 4 + 5, TILE_SIZE / 4 - 10, 0x000000, "MOVE COUNT");
	mlx_string_put(image->mlx, image->win, TILE_SIZE / 4 + 30, TILE_SIZE / 4 + 5, 0x000000, ft_itoa(map->move_count));
	if (image->end_game == 1)
		mlx_string_put(image->mlx, image->win,
			(player_pos.y * TILE_SIZE) + (TILE_SIZE / 4) + 10, 
			(player_pos.x * TILE_SIZE) + (TILE_SIZE / 4) - 10,
			0x000000, "GAME WON");
	if (image->end_game == 2)
		mlx_string_put(image->mlx, image->win,
			(player_pos.y * TILE_SIZE) + (TILE_SIZE / 4) + 5, 
			(player_pos.x * TILE_SIZE) + (TILE_SIZE / 4) - 10,
			0x000000, "GAME LOST");
}

void	*find_content(t_image *image, char c)
{
	t_sprite	*tmp;

	tmp = image->list;
	while (tmp)
	{
		if (c == '1' && tmp->behavior == image->wall_behavior)
			return (tmp->content);
		else if (c == 'P' && tmp->c == 'P' && tmp->behavior == image->player_behavior)
			return (tmp->content);
		else if (c == 'E' && tmp->c == 'E' && tmp->behavior == image->exit_behavior)
			return (tmp->content);
		else if (c != '1' && c != 'P' && c != 'E' && tmp->c == c)
			return (tmp->content);
		tmp = tmp->next;
	}
	return (NULL);
}

int	load_map(t_data *data)
{	
	int		x;
	int		y;
	t_image	*image;
	t_map	*map;
	
	map = data->map;
	image = data->image;
	if (map->collectible_count == 0)
		image->exit_behavior = 'E';
	x = -1;
	while (++x < map->size.height)
	{
		y = -1;
		while (++y < map->size.width)
		{
			if (image->map_first_load || map->tab[x][y] != '1' )
			{
				mlx_put_image_to_window(image->mlx, image->win,
					find_content(image, map->tab[x][y]), (y * TILE_SIZE), (x * TILE_SIZE));
			}
		}
	}
	display_text(map, image);
	image->map_first_load = 0;
	return (1);
}

int	load_animated_walls(t_data *data)
{	
	int		x;
	int		y;
	t_image	*image;
	t_map	*map;
	
	map = data->map;
	image = data->image;
	image->map_delay += 1;
	if (image->map_delay != INT_DELAY)
		return (0);
	else if (image->map_delay == INT_DELAY)
		image->map_delay = 0;
	image->wall_behavior += 1;
	if (image->wall_behavior == '4')
		image->wall_behavior = '0';
	x = -1;
	while (++x < map->size.height)
	{
		y = -1;
		while (++y < map->size.width)
		{
			if (map->tab[x][y] == '1')
			{
				mlx_put_image_to_window(image->mlx, image->win,
					find_content(image, map->tab[x][y]), (y * TILE_SIZE), (x * TILE_SIZE));
			}
		}
	}
	display_text(map, image);
	return (1);
}
