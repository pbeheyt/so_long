/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:56:10 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/06/24 10:45:42 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_xpm(t_image *image)
{
	image->empty = mlx_xpm_file_to_image(image->mlx, "img/empty.xpm", &image->width, &image->height);
	image->wall = mlx_xpm_file_to_image(image->mlx, "img/bush.xpm", &image->width, &image->height);
	image->collectible = mlx_xpm_file_to_image(image->mlx, "img/cheese.xpm", &image->width, &image->height);
	image->exit = mlx_xpm_file_to_image(image->mlx, "img/oball.xpm", &image->width, &image->height);
	image->player = mlx_xpm_file_to_image(image->mlx, "img/rrat.xpm", &image->width, &image->height);
}

void	display_image(t_map *map, t_image *image)
{
	int	content;
	
	content = map->tab[image->y][image->x];
	if (content == '0')
		mlx_put_image_to_window(image->mlx, image->win, image->empty,
			(image->x * 64), (image->y * 64));
	else if (content == '1')
		mlx_put_image_to_window(image->mlx, image->win, image->wall,
			(image->x * 64), (image->y * 64));
	else if (content == 'C')
		mlx_put_image_to_window(image->mlx, image->win, image->collectible,
			(image->x * 64), (image->y * 64));
	else if (content == 'E')
		mlx_put_image_to_window(image->mlx, image->win, image->exit,
			(image->x * 64), (image->y * 64));
	else if (content == 'P')
		mlx_put_image_to_window(image->mlx, image->win, image->player,
			(image->x * 64), (image->y * 64));
}

void	load_map(t_data *data)
{	
	data->image->x = 0;
	data->image->y = 0;

	init_xpm(data->image);
	while (data->image->y < data->map->height)
	{
		data->image->x = 0;
		while (data->image->x < data->map->width)
		{
			display_image(data->map, data->image);
		data->image->x += 1;
		}
	data->image->y += 1;
	}
	
	
}