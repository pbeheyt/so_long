/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:56:10 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/06/25 15:02:43 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_map *init_map(int ac , char **av)
{
	t_map	*map;
	
	if (ac != 2)
	{
		ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
		return (NULL);	
	}
	map = malloc(sizeof(t_map));
	if (!map)
	{
		ft_putstr_fd("Error\nMemory allocation failed\n", 2);
		return (NULL);	
	}
	map->name = av[1];
	map->error = 0;
	map->move_count = 0;
	map->collectible_count = 0;
	map->tab = parse_map_into_table(map);
	if (!map->tab)
		return (free(map), NULL);
	return (map);
}

static t_image *init_mlx(t_map *map)
{
	t_image	*image;
	
	image = malloc(sizeof(t_image));
	if (!image)
	{
		ft_putstr_fd("Error\nMemory allocation failed\n", 2);
		free(map);
		return (NULL);	
	}
	image->mlx = mlx_init();
	image->win = mlx_new_window(image->mlx, map->size.width * 64,
		map->size.height * 64, "SO_LONG");
	image->sprites_loaded = 0;
	return (image);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_map	*map;
	t_image	*image;
	
	map = init_map(ac, av);
	if (!map || !check_map(map))
		return (0);
	data.map = map;
	image = init_mlx(map);
	if (!image)
		return (0);
	data.image = image;
	load_map(map, image, &data);
	mlx_key_hook(image->win, keyboard_input, &data);
	mlx_hook(image->win, 17, 0, clear_all, &data);
	mlx_loop(image->mlx);
	return (1);
}
