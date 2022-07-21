/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:56:10 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/07/21 01:45:00 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	display_map_error(int error)
{
	if (error == 1)
		ft_putstr_fd("Error\nInvalid map dimensions\n", 2);
	if (error == 2)
		ft_putstr_fd("Error\nInvalid map walls\n", 2);
	if (error == 3)
		ft_putstr_fd("Error\nInvalid map content\n", 2);
	if (error == 4)
		ft_putstr_fd(
			"Error\nMap must include 1 Player, 1 Exit & at least 1 Item\n", 2);
}

int	check_map(t_map *map)
{
	check_map_dimensions(map);
	check_walls(map);
	check_content(map);
	if (map->error)
	{
		display_map_error(map->error);
		free_tab(map->tab);
		return (0);
	}
	return (1);
}
