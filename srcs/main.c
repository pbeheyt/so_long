/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:56:10 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/06/25 03:19:58 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_data	data;
	
	data.image = malloc(sizeof(t_image));
	data.map = malloc(sizeof(t_map));
	if (!data.map || !data.image)
		return (0);
	data.map->name = "map.txt";
	data.error = 0;
	data.map->tab = parse_map_into_table(&data);
	check_map(&data);



	data.image->mlx = mlx_init();
	data.image->win = mlx_new_window(data.image->mlx, 
		data.map->size.width * 64, data.map->size.height * 64, "SO_LONG");
	load_map(&data);
	mlx_loop(data.image->mlx);	



	if (!data.error)
		free_tab(data.map->tab);
	return (0);
}
/*	
	printf("error : %d\n", data.error);
	printf("height : %d\n", data.map->height);
	printf("width : %d\n", data.map->width);
	printf("collectible : %d\n", data.map->collectible_count);
	
	
	
	printf("%d\n", check_map(map, &data));
	printf("height : %d\n", data.map_height);
	printf("width : %d\n", data.map_width);
	// printf("%d\n", check_walls(map, &data));
	// printf("%d\n", check_content(map, &data));
	printf("collectible : %d\n", data.collectible_count);
*/