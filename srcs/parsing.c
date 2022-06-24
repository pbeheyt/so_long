/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:56:10 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/06/24 05:37:16 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*put_map_into_str(t_data *data)
{
	char	*row;
	char	*str;
	char	*tmp;
	int		fd;

	fd = open(data->map->name, O_RDONLY);
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

char	**parse_map_into_table(t_data *data)
{
	char	*str;
	char	**map;

	str = put_map_into_str(data);
	if (!str)
		return (0);
	map = ft_split(str, '\n');
	if (!map)
		return (0);
	free(str);
	return (map);
}

void	free_tab(char **tab)
{	
	int	i;

	if (!tab)
		return ;
	i = -1;
	while (tab[++i])
		free(tab[i]);
	free (tab);
}
