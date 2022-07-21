/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:56:10 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/07/21 06:17:11 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static char	*put_map_into_str(int fd, t_map *map)
{
	char	*row;
	char	*str;
	char	*tmp;

	str = malloc(sizeof(char));
	if (!str)
	{
		ft_putstr_fd("Error\nMemory allocation failed\n", 2);
		return (NULL);
	}
	str[0] = 0;
	while (1)
	{
		row = get_next_line(fd);
		if (!row)
			break ;
		if (ft_strlen(row) < 4)
			map->error = 1;
		tmp = ft_strjoin(str, row);
		free (str);
		str = tmp;
		free(row);
	}
	close(fd);
	return (str);
}

char	**parse_map_into_table(t_map *map)
{
	char	*str;
	char	**tab;
	int		fd;

	fd = open(map->name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nInvalid map file\n", 2);
		return (NULL);
	}
	str = put_map_into_str(fd, map);
	if (!str)
		return (NULL);
	tab = ft_split(str, '\n');
	free(str);
	if (!tab)
	{
		ft_putstr_fd("Error\nMemory allocation failed\n", 2);
		return (NULL);
	}
	return (tab);
}
