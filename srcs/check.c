/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:56:10 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/06/25 15:11:26 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(t_map *map)
{
	check_map_file(map);
	check_map_dimensions(map);
	check_walls(map);
	check_content(map);
	if (map->error)
	{
		ft_putstr_fd("Error\nInvalid map\n", 2);
		free_tab(map->tab);
		free(map);
		return (0);
	}
	return (1);
}

void	check_map_file(t_map *map)
{
	int	fd;

	fd = open(map->name, O_RDONLY);
	if (fd == -1)
		map->error = 1;
}
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

int	check_horizontal_wall(char *row)
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
			map->error = 1;
	}
	if (!check_horizontal_wall(map->tab[0]) ||
		!check_horizontal_wall(map->tab[h - 1]))
		map->error = 1;
}
