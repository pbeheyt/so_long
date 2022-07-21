/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:56:10 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/07/21 06:16:52 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	keyboard_input(int keycode, t_data *data)
{
	if (keycode == 65307)
		clear_all(data);
	if (data->image->end_game)
		return (1);
	if (keycode == 'W' || keycode == 'w')
		move_player(data->map, data->image, data, UP);
	if (keycode == 'S' || keycode == 's')
		move_player(data->map, data->image, data, DOWN);
	if (keycode == 'A' || keycode == 'a')
		move_player(data->map, data->image, data, LEFT);
	if (keycode == 'D' || keycode == 'd')
		move_player(data->map, data->image, data, RIGHT);
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
