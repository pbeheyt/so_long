/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:56:10 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/06/26 10:23:14 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_content(char c, int *exit_count, int *player_count, t_map *map)
{
	if (c == 'C')
		map->collectible_count += 1;
	else if (c == 'E')
		*exit_count += 1;
	else if (c == 'P')
		*player_count += 1;
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P')
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
				map->error = 1;
				return ;
			}
		}
	}
	if (exit_count != 1 || player_count != 1)
		map->error = 1;
}
