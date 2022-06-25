/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:56:10 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/06/25 15:50:07 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keyboard_input(int keycode, t_data *data)
{
	if (keycode == 65307)
		clear_all(data);
	else if (keycode == 'W' || keycode == 'w')
		move_player_dir(data->map, data->image, data, UP);
	else if (keycode == 'S' || keycode == 's')
		move_player_dir(data->map, data->image, data, DOWN);
	else if (keycode == 'A' || keycode == 'a')
		move_player_dir(data->map, data->image, data, LEFT);
	else if (keycode == 'D' || keycode == 'd')
		move_player_dir(data->map, data->image, data, RIGHT);
	return (0);
}

t_pos	find_player_position(t_map *map, t_image *image)
{	
	t_sprite	*sprite;
	t_pos		player_pos;
	int			x;
	int			y;

	(void)image;
	sprite = image->player;
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

void	move_player_dir(t_map *map, t_image *image, t_data *data, int dir)
{
	t_pos	delta;

	delta.x = 0;
	delta.y = 0;
	if (dir == UP)
		delta.x = -1;
	if (dir == DOWN)
		delta.x = 1;
	if (dir == LEFT)
		delta.y = -1;
	if (dir == RIGHT)
		delta.y = 1;
	move_player(map, image, data, delta);
}

void	move_player(t_map *map, t_image *image, t_data *data, t_pos delta)
{
	t_pos	player_pos;

	player_pos = find_player_position(map, image);
	if (map->tab[player_pos.x + delta.x][player_pos.y + delta.y]
			== image->wall->c)
		return ;
	if (map->tab[player_pos.x + delta.x][player_pos.y + delta.y]
			== image->collectible->c)
		map->collectible_count--;
	if (map->tab[player_pos.x + delta.x][player_pos.y + delta.y]
			== image->exit->c)
	{
		if (map->collectible_count == 0)
			clear_all(data);
		else
			return ;
	}
	map->tab[player_pos.x][player_pos.y] = image->empty->c;
	map->tab[player_pos.x + delta.x][player_pos.y + delta.y] = image->player->c;
	map->move_count++;
	load_map(map, image, data);
}
