/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:56:10 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/07/15 06:07:25 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keyboard_input(int keycode, t_data *data)
{
	if (keycode == 65307)
		clear_all(data);
	if (data->image->end_game)
		return (1);
	if (keycode == 'W' || keycode == 'w')
		move_player_dir(data->map, data->image, data, UP);
	if (keycode == 'S' || keycode == 's')
		move_player_dir(data->map, data->image, data, DOWN);
	if (keycode == 'A' || keycode == 'a')
		move_player_dir(data->map, data->image, data, LEFT);
	if (keycode == 'D' || keycode == 'd')
		move_player_dir(data->map, data->image, data, RIGHT);
	return (0);
}

t_pos	find_player_position(t_map *map)
{	
	t_pos		player_pos;
	int			x;
	int			y;

	player_pos.x = 0;
	player_pos.y = 0;
	x = -1;
	while (++x < map->size.height)
	{
		y = -1;
		while (++y < map->size.width)
		{
			if (map->tab[x][y] == 'P')
			{
				player_pos.x = x;
				player_pos.y = y;
				return (player_pos);
			}
		}
	}
	return (player_pos);
}

void	move_player_dir(t_map *map, t_image *image, t_data *data, int dir)
{
	t_pos	delta;

	delta.x = 0;
	delta.y = 0;
	if (dir == UP)
	{
		delta.x = -1;
		image->player_behavior = 'U';
	}
	if (dir == DOWN)
	{
		delta.x = 1;
		image->player_behavior = 'D';
	}	
	if (dir == LEFT)
	{
		delta.y = -1;
		image->player_behavior = 'L';
	}
	if (dir == RIGHT)
	{
		delta.y = 1;
		image->player_behavior = 'R';
	}
	move_player(map, image, data, delta);
}

void	move_player(t_map *map, t_image *image, t_data *data, t_pos delta)
{
	t_pos	player_pos;

	player_pos = find_player_position(map);
	if (map->tab[player_pos.x + delta.x][player_pos.y + delta.y]== '1')
		return ;
	if (map->tab[player_pos.x + delta.x][player_pos.y + delta.y] == 'C')
		map->collectible_count--;
	if (map->tab[player_pos.x + delta.x][player_pos.y + delta.y] == 'E')
	{
		if (map->collectible_count == 0)
			image->end_game = 1;
		else
			return ;
	}
	if (map->tab[player_pos.x + delta.x][player_pos.y + delta.y] == 'O')
	{
		image->player_behavior = 'K';
		map->tab[player_pos.x + delta.x][player_pos.y + delta.y] = 'P';
		map->tab[player_pos.x][player_pos.y] = 'O';
		load_map(data);
		image->end_game = 2;
	}
	map->tab[player_pos.x][player_pos.y] = '0';
	map->tab[player_pos.x + delta.x][player_pos.y + delta.y] = 'P';
	map->move_count++;
	load_map(data);
}