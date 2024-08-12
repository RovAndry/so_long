/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   road_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 08:31:38 by randrina          #+#    #+#             */
/*   Updated: 2024/08/12 14:43:47 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(char **map, int x, int y, t_map *maps)
{
	if (x < 0 || y < 0 || x >= maps->width || y >= maps->height)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'R')
		return ;
	map[y][x] = 'R';
	flood_fill(map, x + 1, y, maps);
	flood_fill(map, x - 1, y, maps);
	flood_fill(map, x, y + 1, maps);
	flood_fill(map, x, y - 1, maps);
}

static int	ft_check_arg(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'P' || map[y][x] == 'E')
				return (0);
			x ++;
		}
		y ++;
	}
	return (1);
}

void	ft_check_road(char **map, t_map *map_info, char **map_cp)
{
	flood_fill(map, map_info->px, map_info->py, map_info);
	if (ft_check_arg(map) == 0)
	{
		tab_free(map_cp);
		free(map_info);
		exit_map_error(map);
	}
}
