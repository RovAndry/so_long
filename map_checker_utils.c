/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 08:44:00 by randrina          #+#    #+#             */
/*   Updated: 2024/08/08 00:12:09 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	map_width(char **map)
{
	int	width;

	width = 0;
	while (map[0][width])
		width ++;
	return (width);
}

static int	map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height ++;
	return (height);
}

int	check_map_format(char **map)
{
	int	x;
	int	y;
	int	width;
	int	height;

	width = map_width(map);
	height = map_height(map);
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

char	**all_chek(char *input)
{
	char	**map;
	char	**map_cp;
	t_map	*maps;

	map = map_check(input);
	if (map != NULL)
	{
		maps = create_struct();
		insert_info(maps, map);
		map_cp = map_cpy(map);
		ft_check_road(map, maps, map_cp);
		tab_free(map);
		free(maps);
	}
	return (map_cp);
}
