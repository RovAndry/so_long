/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:36:53 by randrina          #+#    #+#             */
/*   Updated: 2024/08/01 14:46:22 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*create_struct(void)
{
	t_map *map_info;

	map_info = (t_map *) malloc (sizeof (t_map) + 1);
	if (map_info == NULL)
		return (NULL);
	return (map_info);
}

void	insert_surf(t_map *map_info, char **map)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	while (map[height])
		height ++;
	while (map[0][width])
		width ++;
	map_info->width = width;
	map_info->height = height;
}

void	insert_play_pos(t_map *map_info, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				map_info->px = x;
				map_info->py = y;
			}
			x ++;
		}	
		y ++;
	}
}

void	insert_exit_pos(t_map *map_info, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
			{
				map_info->ex = x;
				map_info->ey = y;

			}
			x ++;
		}
		y ++;
	}
}

void	insert_info(t_map *map_info, char **map)
{
	insert_surf(map_info, map);
	insert_play_pos(map_info, map);
	insert_exit_pos(map_info, map);
}
