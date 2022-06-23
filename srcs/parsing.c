/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:56:10 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/06/23 11:27:24 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*put_map_into_str(char *map_name)
{
	char	*row;
	char	*str;
	char 	*tmp;
	int		fd;
	
	fd = open(map_name, O_RDONLY);
	str = malloc(sizeof(char));
	if (!str)
		return (0);
	str[0] = 0;
	while (1)
	{
		row = get_next_line(fd);
		if (!row)
			break ;
		tmp = ft_strjoin(str, row);
		free (str);
		str = tmp;
		free(row);
	}
	close(fd);
	return (str);
}

char **parse_map_into_table(char *map_name)
{
	char	*str;
	char	**map;

	str = put_map_into_str(map_name);
	if (!str)
		return (0);
	map = ft_split(str, '\n');
	if (!map)
		return (0);
	return (map);
}