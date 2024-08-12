/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 21:48:15 by randrina          #+#    #+#             */
/*   Updated: 2024/08/08 09:42:23 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	file_check(char *map)
{
	int		fd;
	char	*ext;
	char	*map_c;

	map_c = ft_strrchr(map, '/');
	if (map_c)
		map_c += 1;
	else
		map_c = map;
	ext = ft_strrchr(map, '.');
	if (ext == NULL || ft_strncmp(".ber", ext, 5) || ft_strlen(map_c) <= 4
		|| *map_c == '.')
	{
		ft_putstr_fd("Error\nWrong file !\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	else
		fd = open(map, O_RDONLY);
	return (fd);
}

static char	**map_insert(int fd)
{
	char	**table;
	char	*full;
	char	*line;

	full = empty_check(fd);
	if (full == NULL)
		full = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		full = ft_strjoin(full, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (map_arg_check(full) == 0)
	{
		free(full);
		ft_putstr_fd("Error\nWrong map !\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	table = ft_split(full, '\n');
	free(full);
	return (table);
}

static int	check_format(char **table)
{
	int		line;
	size_t	length;

	line = 0;
	length = ft_strlen(table[line]);
	while (table[line])
	{
		if (length != ft_strlen(table[line]))
			return (0);
		line ++;
	}
	return (1);
}

void	check_elem(char **map)
{
	if (exit_check(map) == 0 && perso_check(map) == 0)
	{
		if (collec_check(map) > 0)
			exit_no_elem(map, "perso and exit !\n");
		else
			exit_no_elem(map, "perso, collect && exit !\n");
	}
	else if (exit_check(map) > 1 && perso_check(map) > 1)
		exit_many_elem(map, "perso and exit !\n");
	else if (exit_check(map) == 0)
		exit_no_elem(map, "exit !\n");
	else if (exit_check(map) > 1)
		exit_many_elem(map, "exit !\n");
	else if (perso_check(map) == 0)
		exit_no_elem(map, "perso !\n");
	else if (perso_check(map) > 1)
		exit_many_elem(map, "perso !\n");
	else if (collec_check(map) == 0)
		exit_no_elem(map, "collect !\n");
}

char	**map_check(char *map)
{
	char	**map_table;
	int		fd;

	fd = file_check(map);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nWrong file !\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	map_table = map_insert(fd);
	if (!check_format(map_table))
		exit_map_error(map_table);
	check_elem(map_table);
	if (check_map_format(map_table) == 0)
		exit_map_error(map_table);
	return (map_table);
}
