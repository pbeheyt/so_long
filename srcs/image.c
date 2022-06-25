/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:56:10 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/06/25 05:28:50 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sprite	*init_sprite(t_data *data, char *path, char c)
{
	t_sprite	*sprite;
	
	sprite = malloc(sizeof(t_sprite));
	if (!sprite)
	{
		data->error = 1;
		return (0);		
	}
	sprite->path = path;
	sprite->c = c;
	sprite->next = NULL;
	sprite->content = mlx_xpm_file_to_image(data->image->mlx, sprite->path, 
		&sprite->size.width, &sprite->size.height);
	return (sprite);
}

void	load_sprites(t_data *data)
{
	t_image		*image;
	
	image = data->image;
	image->list = NULL;
	image->empty = init_sprite(data, "img/empty.xpm", '0');
	list_add_back(&image->list, image->empty);
	image->wall = init_sprite(data, "img/bush.xpm", '1');
	list_add_back(&image->list, image->wall);
	image->collectible = init_sprite(data, "img/cheese.xpm", 'C');
	list_add_back(&image->list, image->collectible);
	image->exit = init_sprite(data, "img/oball.xpm", 'E');
	list_add_back(&image->list, image->exit);
	image->player = init_sprite(data, "img/rrat.xpm", 'P');
	list_add_back(&image->list, image->player);
}

void	*find_content(t_image *image, char c)
{
	t_sprite	*tmp;
	
	tmp = image->list;
	while (tmp)
	{
		if (tmp->c == c)
			return (tmp->content);
		tmp = tmp->next;
	}
	return (NULL);
}

void	load_map(t_data *data)
{	
	t_image	*image;
	t_map	*map;
	int		x;
	int		y;
	int		c;

	load_sprites(data);
	image = data->image;
	map = data->map;
	x = -1;
	while (++x < map->size.height)
	{
		y = -1;
		while (++y < map->size.width)
		{
			c = map->tab[x][y];
			mlx_put_image_to_window(image->mlx, image->win, find_content(image, c),
				(y * 64), (x * 64));
		}
	}
}