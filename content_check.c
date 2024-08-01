/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 04:19:06 by randrina          #+#    #+#             */
/*   Updated: 2024/08/01 08:43:42 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_check(char **map)
{
	int	x;
	int	y;
	int	e;

	y = 0;
	e = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
				e ++;
			x ++;
		}
		y ++;
	}
	return (e);
}

int	perso_check(char **map)
{
	int	x;
	int	y;
	int	p;

	y = 0;
	p = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				p ++;
			x ++;
		}
		y ++;
	}
	return (p);
}

int	collec_check(char **map)
{
	int	x;
	int	y;
	int	c;

	c = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				c ++;
			x ++;
		}
		y ++;
	}
	return (c);
}

void	exit_many_elem(char **map, char *elem)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i ++;
	}
	free(map);
	ft_putstr_fd("too many ", STDERR_FILENO);
	ft_putstr_fd(elem, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	exit_no_elem(char **map, char *elem)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i ++;
	}
	free(map);
	ft_putstr_fd("map no ", STDERR_FILENO);
	ft_putstr_fd(elem, STDERR_FILENO);
	exit(EXIT_FAILURE);
	
}
