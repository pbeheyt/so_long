/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:56:10 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/07/26 07:15:49 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
		mlx_destroy_image(image->mlx, tmp->content);
		tmp = tmp->next;
		free (sprite);
	}
	mlx_destroy_window(image->mlx, image->win);
	mlx_destroy_display(image->mlx);
	free(image->mlx);
}

int	clear_all(t_data *data)
{	
	free_tab(data->map->tab);
	clear_mlx(data->image);
	exit (1);
}
