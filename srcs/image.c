/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:56:10 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/06/24 07:34:36 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_xpm(t_map *map, t_image *image)
{
	image->empty = mlx_xpm_file_to_image(&image->mlx,
		"img/empty.xpm", &map->width, &map->height);
	image->wall = mlx_xpm_file_to_image(&image->mlx,
		"img/bush.xpm", &map->width, &map->height);
	image->collectible = mlx_xpm_file_to_image(&image->mlx,
		"img/cheese.xpm", &map->width, &map->height);
	image->exit = mlx_xpm_file_to_image(&image->mlx,
		"img/oball.xpm", &map->width, &map->height);
	image->player = mlx_xpm_file_to_image(&image->mlx,
		"img/rrat.xpm", &map->width, &map->height);
}

void	display_image(t_map *map, t_image *image)
{
	if (map->tab[image->x][image->y] == '0')
		mlx_put_image_to_window(image->mlx, image->win, image->empty,
			(image->x * 64), (image->y * 64));
	else if (map->tab[image->x][image->y] == '1')
		mlx_put_image_to_window(image->mlx, image->win, image->wall,
			(image->x * 64), (image->y * 64));
	else if (map->tab[image->x][image->y] == 'C')
		mlx_put_image_to_window(image->mlx, image->win, image->collectible,
			(image->x * 64), (image->y * 64));
	else if (map->tab[image->x][image->y] == 'E')
		mlx_put_image_to_window(image->mlx, image->win, image->exit,
			(image->x * 64), (image->y * 64));
	else if (map->tab[image->x][image->y] == 'P')
		mlx_put_image_to_window(image->mlx, image->win, image->player,
			(image->x * 64), (image->y * 64));
}

void	load_map(t_data *data)
{	
	data->image->x = 0;
	data->image->y = 0;

	init_xpm(data->map, data->image);
	while (data->image->x < data->map->height)
	{
		while (data->image->y < data->map->width)
		{
			display_image(data->map, data->image);
		data->image->y += 1;
		}
	data->image->x += 1;
	}
	
	
}