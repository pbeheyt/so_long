/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:56:10 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/06/30 15:20:54 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**pathes(void)
{
	static char	*pathes[IMAGE_COUNT] = {
		"image/0S.xpm",
		"image/1S.xpm",
		"image/CS.xpm",
		"image/EE.xpm",
		"image/ES.xpm",
		"image/OS.xpm",
		"image/PK.xpm",
		"image/PD.xpm",
		"image/PL.xpm",
		"image/PR.xpm",
		"image/PS.xpm",
		"image/PU.xpm",
	};

	return (pathes);
}

void	init_sprites(t_image *image, t_data *data)
{
	t_sprite	*sprite;
	char 		**tab;
	int 		i;

	image->list = NULL;
	tab = pathes();
	i = -1;
	while (++i < IMAGE_COUNT)
	{
		sprite = malloc(sizeof(t_sprite));
		if (!sprite)
		{
			ft_putstr_fd("Error\nMemory allocation failed\n", 2);
			clear_all(data);
		}
		sprite->path = tab[i];
		sprite->c = tab[i][6];
		sprite->behavior = tab[i][7];
		sprite->next = NULL;
		sprite->content = mlx_xpm_file_to_image(image->mlx, sprite->path,
			&sprite->size.width, &sprite->size.height);
		list_add_back(&image->list, sprite);
	}
}

void	*find_content(t_image *image, char c)
{
	t_sprite	*tmp;
	
	

	tmp = image->list;
	while (tmp)
	{
		if (c == 'P' && tmp->c == 'P' && tmp->behavior == image->player_behavior)
		{	
			printf("%s\n", tmp->path);
			return (tmp->content);
		}
		else if (c == 'E' && tmp->c == 'E' && tmp->behavior == image->exit_behavior)
			return (tmp->content);
		else if (c != 'P' && c != 'E' && tmp->c == c)
			return (tmp->content);
		tmp = tmp->next;
	}
	return (NULL);
}

void	load_map(t_map *map, t_image *image, t_data *data)
{	
	int		x;
	int		y;
	t_pos	player_pos;

	player_pos = find_player_position(map);

	(void)data;
	if (map->collectible_count == 0)
		image->exit_behavior = 'E';
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
	mlx_string_put(image->mlx, image->win, TILE_SIZE / 4, TILE_SIZE / 4, 0xccccff, "MOVE COUNT");
	mlx_string_put(image->mlx, image->win, TILE_SIZE / 4 + 32, TILE_SIZE / 4 + 16, 0xccccff, ft_itoa(map->move_count));
	if (image->end_game == 1)
		mlx_string_put(image->mlx, image->win,
			(player_pos.y * TILE_SIZE) + (TILE_SIZE / 4), 
			(player_pos.x * TILE_SIZE) + (TILE_SIZE / 4),
			0xccccff, "GAME WIN");
	if (image->end_game == 2)
		mlx_string_put(image->mlx, image->win,
			(player_pos.y * TILE_SIZE) + (TILE_SIZE / 4), 
			(player_pos.x * TILE_SIZE) + (TILE_SIZE / 4),
			0xccccff, "GAME LOST");
}
