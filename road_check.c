/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   road_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 08:31:38 by randrina          #+#    #+#             */
/*   Updated: 2024/08/01 14:47:29 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, int x, int y, t_map *maps)
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

void	ft_check_road(char **map, t_map *map_info)
{
	flood_fill(map, map_info->px, map_info->py, map_info);
	show_map(map);
}
