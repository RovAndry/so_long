/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 08:44:00 by randrina          #+#    #+#             */
/*   Updated: 2024/08/01 12:35:03 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int		check_map_format(char **map)
{
	int	x;
	int	y;
	int	width;
	int	height;

	width = 0;
	height = 0;
	while (map[height])
		height ++;
	while (map[0][width])
		width ++;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if ((x == 0 || x == width - 1) && map[y][x] != '1')
				return (0);
			if ((y == 0 || y == height - 1) && map[y][x] != '1')
				return (0);
			x ++;
		}
		y ++;
	}
	return (1);
}
