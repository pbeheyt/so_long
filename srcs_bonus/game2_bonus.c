/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:56:10 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/07/26 06:59:05 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static t_pos	player_direction(t_image *image, int dir)
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
	return (delta);
}

static void	player_killed(t_image *image)
{
	image->end_game = 2;
	image->player_behavior = 'K';
}

static int	player_on_exit(t_map *map, t_image *image)
{
	if (map->collectible_count == 0)
	{	
		image->end_game = 1;
		image->player_behavior = 'E';
		return (1);
	}
	return (0);
}

void	move_player(t_map *map, t_image *image, t_data *data, int dir)
{
	t_pos	player_pos;
	t_pos	delta;

	player_pos = find_player_position(map);
	delta = player_direction(image, dir);
	if (map->tab[player_pos.x + delta.x][player_pos.y + delta.y] == '1')
		return ;
	if (map->tab[player_pos.x + delta.x][player_pos.y + delta.y] == 'C')
		map->collectible_count--;
	if (map->tab[player_pos.x + delta.x][player_pos.y + delta.y] == 'O')
		player_killed(image);
	if (map->tab[player_pos.x + delta.x][player_pos.y + delta.y] == 'E')
	{
		if (!player_on_exit(map, image))
			return ;
	}
	map->tab[player_pos.x][player_pos.y] = '0';
	map->tab[player_pos.x + delta.x][player_pos.y + delta.y] = 'P';
	map->move_count += 1;
	ft_putnbr_fd(map->move_count, 1);
	ft_putchar_fd('\n', 1);
	load_map(data);
}
