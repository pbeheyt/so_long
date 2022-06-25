/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:56:10 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/06/25 09:57:11 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	clear_all(t_data *data)
{	
	free_tab(data->map->tab);
	clear_mlx(data);
	free_struct(data);
	exit (0);
}

void	free_struct(t_data *data)
{	
	free(data->image);
	free(data->map);
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

void	clear_mlx(t_data *data)
{
	t_image		*image;
	t_sprite	*tmp;
	
	image = data->image;
	tmp = image->list;
	while (tmp)
	{
		mlx_destroy_image(image->mlx, tmp->content);
		tmp = tmp->next;
	}
	mlx_destroy_window(image->mlx, image->win);
	mlx_destroy_display(image->mlx);
	free(image->mlx);
}
