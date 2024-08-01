/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 00:06:23 by randrina          #+#    #+#             */
/*   Updated: 2024/08/01 14:29:00 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	tab_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i ++;
	}
	free(str);
}

int	map_arg_check(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (!(map[i] == '1' || map[i] == '0' || map[i] == 'E' || map[i] == 'P'))
		{
			if (!(map[i] == 'C' || map[i] == '\n'))
				return (0);
		}
		i ++;
	}
	return (1);
}

void	show_info(t_map *map)
{
	printf("px-[%d]--py-[%d]--height[%d]--width[%d]\n", map->px, map->py, map->height, map->width);
}

void	show_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_putstr_fd(map[i], STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
		i ++;
	}
}

void	exit_map_error(char **map)
{
	tab_free(map);
	ft_putstr_fd("wrong map !\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

