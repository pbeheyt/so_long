/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:56:10 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/07/21 02:46:40 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	display_text(t_data *data, t_map *map, t_image *image)
{
	t_pos	player_pos;
	char	*move_count;

	player_pos = find_player_position(map);
	move_count = ft_itoa(map->move_count);
	if (!move_count)
	{
		ft_putstr_fd("Error\nMemory allocation failed\n", 2);
		clear_all(data);
	}
	mlx_string_put(image->mlx, image->win,
		TILE_SIZE / 4 + 5, TILE_SIZE / 4 - 10, 0x000000, "MOVE COUNT");
	mlx_string_put(image->mlx, image->win,
		TILE_SIZE / 4 + 30, TILE_SIZE / 4 + 5, 0x000000, move_count);
	free(move_count);
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

static void	*find_content(t_image *image, char c)
{
	t_sprite	*tmp;

	tmp = image->list;
	while (tmp)
	{
		if (c == '1' && tmp->behavior == image->wall_behavior)
			return (tmp->content);
		else if (c == 'P' && tmp->c == 'P'
			&& tmp->behavior == image->player_behavior)
			return (tmp->content);
		else if (c == 'E' && tmp->c == 'E'
			&& tmp->behavior == image->exit_behavior)
			return (tmp->content);
		else if (c != '1' && c != 'P' && c != 'E' && tmp->c == c)
			return (tmp->content);
		tmp = tmp->next;
	}
	return (NULL);
}

static void	display_map(t_map *map, t_image *image, int walls)
{
	int		x;
	int		y;

	x = -1;
	while (++x < map->size.height)
	{
		y = -1;
		while (++y < map->size.width)
		{
			if (walls && map->tab[x][y] == '1')
				mlx_put_image_to_window(image->mlx, image->win,
					find_content(image, map->tab[x][y]),
					(y * TILE_SIZE), (x * TILE_SIZE));
			if ((!walls && image->map_first_load) || map->tab[x][y] != '1')
				mlx_put_image_to_window(image->mlx, image->win,
					find_content(image, map->tab[x][y]),
					(y * TILE_SIZE), (x * TILE_SIZE));
		}
	}
}

int	load_map(t_data *data)
{	
	t_image	*image;
	t_map	*map;

	map = data->map;
	image = data->image;
	if (map->collectible_count == 0)
		image->exit_behavior = 'E';
	display_map(map, image, 0);
	image->map_first_load = 0;
	display_text(data, map, image);
	return (1);
}

int	load_animated_walls(t_data *data)
{	
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
	display_map(map, image, 1);
	display_text(data, map, image);
	return (1);
}
