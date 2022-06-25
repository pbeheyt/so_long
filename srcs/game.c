/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:56:10 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/06/25 07:48:18 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keyboard_input(int keycode, t_data *data)
{
	if (keycode == 65307)
		free_tab(data->map->tab);
	else if (keycode == 'W' || keycode == 'w')
		move_player_dir(data, UP);
	else if (keycode == 'S' || keycode == 's')
		move_player_dir(data, DOWN);
	else if (keycode == 'A' || keycode == 'a')
		move_player_dir(data, LEFT);
	else if (keycode == 'D' || keycode == 'd')
		move_player_dir(data, RIGHT);
	return (0);
}

t_pos	find_player_position(t_data *data)
{	
	t_sprite	*sprite;
	t_map		*map;
	t_pos		player_pos;
	int			x;
	int			y;

	sprite = data->image->player;
	map = data->map;
	player_pos.x = 0;
	player_pos.y = 0;
	x = -1;
	while (++x < map->size.height)
	{
		y = -1;
		while (++y < map->size.width)
		{
			if (map->tab[x][y] == sprite->c)
			{
				player_pos.x = x;
				player_pos.y = y;
				return (player_pos);
			}
		}
	}
	return (player_pos);
}

void move_player_dir(t_data *data, int dir)
{
	t_pos	delta;
	
	if (dir == UP)
	{
		delta.x = -1;
		delta.y = 0;
	}
	if (dir == DOWN)
	{
		delta.x = 1;
		delta.y = 0;
	}
	if (dir == LEFT)
	{
		delta.x = 0;
		delta.y = -1;
	}
	if (dir == RIGHT)
	{
		delta.x = 0;
		delta.y = 1;
	}
	move_player(data, delta);
}

void move_player(t_data *data, t_pos delta)
{
	t_image	*image;
	t_map	*map;
	t_pos	player_pos;

	image = data->image;
	map = data->map;
	player_pos = find_player_position(data);

	if (map->tab[player_pos.x + delta.x][player_pos.y + delta.y] == image->wall->c)
		return ;
	if (map->tab[player_pos.x + delta.x][player_pos.y + delta.y] == image->collectible->c)
		map->collectible_count--;
	if (map->tab[player_pos.x + delta.x][player_pos.y + delta.y] == image->exit->c)
	{
		if (map->collectible_count == 0)
			return (free_tab(map->tab));
		else
			return ;
	}
	map->tab[player_pos.x][player_pos.y] = image->empty->c;
	map->tab[player_pos.x + delta.x][player_pos.y + delta.y] = image->player->c;
	map->move_count++;
	load_map(data);
}