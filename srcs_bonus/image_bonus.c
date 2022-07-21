/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:56:10 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/07/21 06:16:58 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static char	**pathes(void)
{
	static char	*pathes[IMAGE_COUNT] = {
		"image/0S.xpm",
		"image/10.xpm",
		"image/11.xpm",
		"image/12.xpm",
		"image/13.xpm",
		"image/CS.xpm",
		"image/EE.xpm",
		"image/ES.xpm",
		"image/OS.xpm",
		"image/PK.xpm",
		"image/PD.xpm",
		"image/PL.xpm",
		"image/PR.xpm",
		"image/PU.xpm",
		"image/PE.xpm",
	};

	return (pathes);
}

static t_sprite	*get_list_last(t_sprite *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

static void	list_add_back(t_sprite **lst, t_sprite *new)
{
	t_sprite	*back;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	back = get_list_last(*lst);
	back->next = new;
}

void	init_sprites(t_image *image, t_data *data)
{
	t_sprite	*sprite;
	char		**tab;
	int			i;

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
