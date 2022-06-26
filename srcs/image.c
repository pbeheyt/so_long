/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:56:10 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/06/26 13:54:58 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sprite	*init_sprite(t_image *image, t_data *data, char *path, char c)
{
	t_sprite	*sprite;

	sprite = malloc(sizeof(t_sprite));
	if (!sprite)
	{
		ft_putstr_fd("Error\nMemory allocation failed\n", 2);
		clear_all(data);
	}
	sprite->path = path;
	sprite->c = c;
	sprite->next = NULL;
	sprite->content = mlx_xpm_file_to_image(image->mlx, sprite->path,
			&sprite->size.width, &sprite->size.height);
	return (sprite);
}

char *find_path(t_sprite *sprite)
{
	if (sprite->c == 'E')
	{
		if (sprite->behavior == STATIC)
			return ("img/exit.xpm");
		if (sprite->behavior == END)
			return ("img/exitF.xpm");
	}
	if (sprite->c == 'P')
	{
		if (sprite->behavior == GO_UP)
			return ("img/playerU.xpm");
		if (sprite->behavior == GO_DOWN)
			return ("img/playerD.xpm");
		if (sprite->behavior == GO_LEFT)
			return ("img/playerL.xpm");
		if (sprite->behavior == GO_RIGHT)
			return ("img/playerR.xpm");
		if (sprite->behavior == KILL)
			return ("img/opponentK.xpm");		
	}
	if (sprite->c == 'O')
	{
		if (sprite->behavior == STATIC)
			return ("img/opponentD.xpm");
	}
	return (NULL);
}

void	load_sprites(t_image *image, t_data *data)
{
	image->list = NULL;
	image->empty = init_sprite(image, data, "img/empty.xpm", '0');
	image->wall = init_sprite(image, data, "img/wall.xpm", '1');
	image->collectible = init_sprite(image, data, "img/collectible.xpm", 'C');
	if (!image->sprites_loaded)
	{
		image->exit = init_sprite(image, data, "img/exit.xpm", 'E');
		image->player = init_sprite(image, data, "img/playerU.xpm", 'P');
		image->opponent = init_sprite(image, data, "img/opponentD.xpm", 'O');
	}
	else
	{
		image->exit = init_sprite(image, data, find_path(image->exit), 'E');
		image->player = init_sprite(image, data, find_path(image->player), 'P');
		image->opponent = init_sprite(image, data, find_path(image->opponent), 'O');
	}
	list_add_back(&image->list, image->empty);
	list_add_back(&image->list, image->wall);
	list_add_back(&image->list, image->collectible);
	list_add_back(&image->list, image->exit);
	list_add_back(&image->list, image->player);
	list_add_back(&image->list, image->opponent);
	image->sprites_loaded = 1;
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

void	load_map(t_map *map, t_image *image, t_data *data)
{	
	int		x;
	int		y;

	load_sprites(image, data);
	ft_putnbr_fd(map->move_count, 1);
	ft_putchar_fd('\n', 1);
	if (map->collectible_count == 0)
		image->exit->behavior = END;
	x = -1;
	while (++x < map->size.height)
	{
		y = -1;
		while (++y < map->size.width)
		{
			mlx_put_image_to_window(image->mlx, image->win,
				find_content(image, map->tab[x][y]), (y * TILE_SIZE), (x * TILE_SIZE));
		}
	}
}
