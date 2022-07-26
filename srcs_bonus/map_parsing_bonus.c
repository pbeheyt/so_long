/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:56:10 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/07/26 07:22:53 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	check_row(char *str, t_map *map)
{
	int		i;
	char	*base;
	int		content;

	content = 0;
	base = "01CEPO";
	if (ft_strlen(str) < 4)
		map->error = 1;
	while (*str)
	{
		i = -1;
		while (base[++i])
		{
			if (*str == base[i])
				content = 1;
		}
		if (!content)
			map->error = 3;
	str++;
	}
	if (map->error)
		return (display_map_error(map->error), 0);
	return (1);
}

static char	*put_map_into_str(int fd, t_map *map)
{
	char	*row;
	char	*str;
	char	*tmp;

	str = malloc(sizeof(char));
	if (!str)
		return (ft_putstr_fd("Error\nMemory allocation failed\n", 2), NULL);
	str[0] = 0;
	while (1)
	{
		row = get_next_line(fd);
		if (!row)
			break ;
		if (!check_row(row, map))
			return (get_next_line(-1), free(str), free(row), NULL);
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
		return (ft_putstr_fd("Error\nInvalid map file\n", 2), NULL);
	str = put_map_into_str(fd, map);
	if (!str)
		return (NULL);
	tab = ft_split(str, '\n');
	free(str);
	if (!tab)
		return (ft_putstr_fd("Error\nMemory allocation failed\n", 2), NULL);
	return (tab);
}
