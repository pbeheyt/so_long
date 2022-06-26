/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:56:10 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/06/26 21:34:17 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	clear_all(t_data *data)
{	
	free_tab(data->map->tab);
	clear_mlx(data->image);
	exit (1);
}

void	free_tab(char **tab)
{	
	int	i;

	if (!tab)
		return ;
	i = -1;
	while (tab[++i])
		free(tab[i]);
	free (tab);
}

void	clear_mlx(t_image *image)
{
	t_sprite	*tmp;
	t_sprite	*sprite;

	tmp = image->list;
	while (tmp)
	{
		sprite = tmp;
		printf("destroy : %s\n", tmp->path);
		mlx_destroy_image(image->mlx, tmp->content);
		tmp = tmp->next;
		free (sprite);
	}
	mlx_destroy_window(image->mlx, image->win);
	mlx_destroy_display(image->mlx);
	free(image->mlx);
}
