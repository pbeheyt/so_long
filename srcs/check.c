/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:56:10 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/06/23 15:18:22 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(char **map, t_data *data)
{
	check_map_dimensions(map, data);
	check_walls(map, data);
	check_content(map, data);
	if (data->error)
	{
		free_tab(map);
		return (0);
	}
	return (1);
}


void	check_map_dimensions(char **map, t_data *data)
{
	int	first;
	int	w;
	int	h;

	if (data->error)
		return ;
	first = 0;
	w = 0;
	h = -1;
	while (map[++h])
	{
		w = ft_strlen(map[h]);
		if (first && w != data->map_width)
		{
			data->error = 1;
			return ;
		}
		first = 1;
		data->map_width = w;
	}
	data->map_height = h;
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

void	check_walls(char **map, t_data *data)
{
	int	h;
	int	w;
	int	i;

	if (data->error)
		return ;
	h = data->map_height;
	w = data->map_width;
	i = 0;
	while (++i < (h - 1))
	{
		if (map[i][0] != '1' || map[i][w - 1] != '1')
			data->error = 1;
	}
	if (!check_horizontal_wall(map[0]) || !check_horizontal_wall(map[h - 1]))
		data->error = 1;
}
