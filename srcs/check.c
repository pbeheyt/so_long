/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:56:10 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/06/25 09:36:47 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(t_data *data)
{
	check_map_dimensions(data);
	check_walls(data);
	check_content(data);
	if (data->error)
	{
		free_tab(data->map->tab);
		free_struct(data);
		return (0);
	}
	return (1);
}


void	check_map_dimensions(t_data *data)
{
	int	first;
	int	w;
	int	h;

	if (data->error)
		return ;
	first = 0;
	w = 0;
	h = -1;
	while (data->map->tab[++h])
	{
		w = ft_strlen(data->map->tab[h]);
		if (first && w != data->map->size.width)
		{
			data->error = 1;
			return ;
		}
		first = 1;
		data->map->size.width = w;
	}
	data->map->size.height = h;
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

void	check_walls(t_data *data)
{
	int	h;
	int	w;
	int	i;

	if (data->error)
		return ;
	h = data->map->size.height;
	w = data->map->size.width;
	i = 0;
	while (++i < (h - 1))
	{
		if (data->map->tab[i][0] != '1' || data->map->tab[i][w - 1] != '1')
			data->error = 1;
	}
	if (!check_horizontal_wall(data->map->tab[0]) ||
		!check_horizontal_wall(data->map->tab[h - 1]))
		data->error = 1;
}
