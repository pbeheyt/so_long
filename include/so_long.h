/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 04:41:55 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/06/24 05:41:41 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <mlx.h>
# include "libft.h"

typedef struct s_map
{
	char	*name;
	char 	**tab;
	int		x;
	int		y;
	int		height;
	int		width;
	int		collectible_count;
	int		move_count;
}			t_map;

typedef struct s_image
{
	void	*mlx;
	void	*win;
	void	*empty;
	void	*wall;
	void	*collectible;
	void	*exit;
	void	*player;
}			t_image;

typedef struct s_data
{
	int		error;
	t_map	*map;
	t_image	*image;

}			t_data;
/*parsing.c*/
char	*put_map_into_str(t_data *data);
char	**parse_map_into_table(t_data *data);
void	free_tab(char **tab);

/*check.c*/
int		check_map(t_data *data);
void	check_map_dimensions(t_data *data);
int		check_horizontal_wall(char *row);
void	check_walls(t_data *data);

/*check2.c*/
int		is_content(char c, int *exit_count, int *player_count, t_data *data);
void	check_content(t_data *data);

#endif