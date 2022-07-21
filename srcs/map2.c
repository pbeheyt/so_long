/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:56:10 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/07/21 01:41:45 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_dimensions(t_map *map)
{
	int	first;
	int	w;
	int	h;

	if (map->error)
		return ;
	first = 0;
	w = 0;
	h = -1;
	while (map->tab[++h])
	{
		w = ft_strlen(map->tab[h]);
		if (first && w != map->size.width)
		{
			map->error = 1;
			return ;
		}
		first = 1;
		map->size.width = w;
	}
	map->size.height = h;
}

static int	check_horizontal_wall(char *row)
{
	int	i;

	i = -1;
	while (row[++i])
	{
		if (row[i] != '1')
			return (0);
	}
	return (1);
}

void	check_walls(t_map *map)
{
	int	h;
	int	w;
	int	i;

	if (map->error)
		return ;
	h = map->size.height;
	w = map->size.width;
	i = 0;
	while (++i < (h - 1))
	{
		if (map->tab[i][0] != '1' || map->tab[i][w - 1] != '1')
			map->error = 2;
	}
	if (!check_horizontal_wall(map->tab[0])
		|| !check_horizontal_wall(map->tab[h - 1]))
		map->error = 2;
}

static int	is_content(char c, int *exit_count, int *player_count, t_map *map)
{
	if (c == 'C')
		map->collectible_count += 1;
	else if (c == 'E')
		*exit_count += 1;
	else if (c == 'P')
		*player_count += 1;
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P' || c == 'O')
		return (1);
	return (0);
}

void	check_content(t_map *map)
{
	int	i;
	int	j;
	int	exit_count;
	int	player_count;

	if (map->error)
		return ;
	exit_count = 0;
	player_count = 0;
	i = 0;
	while (++i < (map->size.height - 1))
	{
		j = 0;
		while (++j < (map->size.width - 1))
		{
			if (!is_content(map->tab[i][j], &exit_count, &player_count, map))
			{
				map->error = 3;
				return ;
			}
		}
	}
	if (exit_count != 1 || player_count != 1 || map->collectible_count < 1)
		map->error = 4;
}
