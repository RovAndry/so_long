/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 00:06:23 by randrina          #+#    #+#             */
/*   Updated: 2024/08/12 14:46:54 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	tab_free(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i ++;
	}
	free(str);
}

char	*empty_check(int fd)
{
	char	*map;

	map = get_next_line(fd);
	if (map == NULL)
	{
		free(map);
		ft_putstr_fd("Error\nWrong map !\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (map);
}

int	map_arg_check(char *map)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	if (map[i] != '1')
		return (0);
	while (map[i])
	{
		if (map[i] == '\n')
			flag = 1;
		if (map[i] == '\n' && map[i + 1] == '\n')
			return (0);
		if (!(map[i] == '1' || map[i] == '0' || map[i] == 'E' || map[i] == 'P'
				|| map[i] == 'C' || map[i] == '\n'))
			return (0);
		i ++;
	}
	if (flag == 0)
		return (0);
	return (1);
}

char	**map_cpy(char **map)
{
	int		y;
	char	**cpy;
	int		index;

	y = 0;
	while (map[y])
		y ++;
	cpy = (char **) malloc (sizeof (char *) * (y + 1));
	if (cpy == NULL)
		return (NULL);
	index = 0;
	while (index < y)
	{
		cpy[index] = ft_strdup(map[index]);
		if (cpy[index] == NULL)
		{
			tab_free(cpy);
			return (NULL);
		}
		index ++;
	}
	cpy[index] = NULL;
	return (cpy);
}

void	exit_map_error(char **map)
{
	tab_free(map);
	ft_putstr_fd("Error\nWrong map !\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
