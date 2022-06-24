/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:56:10 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/06/25 01:03:02 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_xpm(t_image *image)
{
	image->empty = mlx_xpm_file_to_image(image->mlx, "img/empty.xpm", 
		&image->size.width, &image->size.height);
	image->wall = mlx_xpm_file_to_image(image->mlx, "img/bush.xpm", 
		&image->size.width, &image->size.height);
	image->collectible = mlx_xpm_file_to_image(image->mlx, "img/cheese.xpm", 
		&image->size.width, &image->size.height);
	image->exit = mlx_xpm_file_to_image(image->mlx, "img/oball.xpm", 
		&image->size.width, &image->size.height);
	image->player = mlx_xpm_file_to_image(image->mlx, "img/rrat.xpm", 
		&image->size.width, &image->size.height);
}

void	display_image(t_map *map, t_image *image)
{
	int	content;
	
	content = map->tab[image->x][image->y];
	if (content == '0')
		mlx_put_image_to_window(image->mlx, image->win, image->empty,
			(image->y * 64), (image->x * 64));
	else if (content == '1')
		mlx_put_image_to_window(image->mlx, image->win, image->wall,
			(image->y * 64), (image->x * 64));
	else if (content == 'C')
		mlx_put_image_to_window(image->mlx, image->win, image->collectible,
			(image->y * 64), (image->x * 64));
	else if (content == 'E')
		mlx_put_image_to_window(image->mlx, image->win, image->exit,
			(image->y * 64), (image->x * 64));
	else if (content == 'P')
		mlx_put_image_to_window(image->mlx, image->win, image->player,
			(image->y * 64), (image->x * 64));
}

void	load_map(t_map *map, t_image *image)
{	
	image->x = 0;
	image->y = 0;

	init_xpm(image);
	while (image->x < map->size.height)
	{
		image->y = 0;
		while (image->y < map->size.width)
		{
			display_image(map, image);
		image->y += 1;
		}
	image->x += 1;
	}
}