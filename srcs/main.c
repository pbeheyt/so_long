/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:56:10 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/07/26 06:52:52 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_map(t_map *map, int ac, char **av)
{	
	if (ac != 2)
		return (ft_putstr_fd("Error\nInvalid number of arguments\n", 2), 0);
	map->name = av[1];
	map->error = 0;
	map->move_count = 0;
	map->collectible_count = 0;
	map->tab = parse_map_into_table(map);
	if (!map->tab)
		return (0);
	return (1);
}

int	init_mlx(t_map *map, t_image *image, t_data *data)
{
	image->mlx = mlx_init();
	if (!image->mlx)
		return (free_tab(map->tab), 0);
	image->win = mlx_new_window(image->mlx, map->size.width * TILE_SIZE,
			map->size.height * TILE_SIZE, "SO_LONG");
	image->map_first_load = 1;
	image->sprites_loaded = 0;
	image->map_delay = 0;
	image->end_game = 0;
	init_sprites(image, data);
	image->exit_behavior = 'S';
	image->player_behavior = 'D';
	image->wall_behavior = '0';
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_map	map;
	t_image	image;

	if (!init_map(&map, ac, av) || !check_map(&map)
		|| !init_mlx(&map, &image, &data))
		return (0);
	data.map = &map;
	data.image = &image;
	load_map(&data);
	image.map_first_load = 0;
	mlx_key_hook(image.win, keyboard_input, &data);
	mlx_hook(image.win, 17, 0, clear_all, &data);
	mlx_loop_hook(image.mlx, load_animated_walls, &data);
	mlx_loop(image.mlx);
	return (1);
}
