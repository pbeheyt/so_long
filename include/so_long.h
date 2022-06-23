/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 04:41:55 by pbeheyt           #+#    #+#             */
/*   Updated: 2022/06/23 15:18:44 by pbeheyt          ###   ########.fr       */
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

typedef struct s_data
{
	char	*map_name;
	int		error;
	int		map_height;
	int		map_width;
	int		collectible_count;
}			t_data;

/*parsing.c*/
char	*put_map_into_str(t_data *data);
char	**parse_map_into_table(t_data *data);
void	free_tab(char **tab);

/*check.c*/
int		check_map(char **map, t_data *data);
void	check_map_dimensions(char **map, t_data *data);
int		check_horizontal_wall(char *row);
void	check_walls(char **map, t_data *data);

/*check2.c*/
int		is_content(char c, int *exit_count, int *player_count, t_data *data);
void	check_content(char **map, t_data *data);

#endif