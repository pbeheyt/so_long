/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:56:10 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/06/23 15:07:18 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	char	**map;
	t_data	data;

	data.map_name = "map.txt";
	data.error = 0;
	map = parse_map_into_table(&data);
	check_map(map, &data);
	if (!data.error)
		free_tab(map);
	return (0);
}
/*
	printf("%d\n", check_map(map, &data));
	printf("height : %d\n", data.map_height);
	printf("width : %d\n", data.map_width);
	// printf("%d\n", check_walls(map, &data));
	// printf("%d\n", check_content(map, &data));
	printf("collectible : %d\n", data.collectible_count);
*/