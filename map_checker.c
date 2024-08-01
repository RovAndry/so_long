/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 21:48:15 by randrina          #+#    #+#             */
/*   Updated: 2024/08/01 14:01:47 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	file_check(char *map)
{
	int		fd;
	char	*ext;
	char	*real_ext;

	real_ext = ".ber";
	ext = ft_strrchr(map, '.');
	if (ext == NULL || ft_strncmp(real_ext, ext, 5))
	{
		ft_putstr_fd("wrong file !\n", STDERR_FILENO);
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

	full = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		full = ft_strjoin(full, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	table = ft_split(full, '\n');
	if (!map_arg_check(full))
	{
		ft_putstr_fd("wrong map !\n", STDERR_FILENO);
		free(full);
		exit(EXIT_FAILURE);
	}
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
		exit_no_elem(map, "collect !");
}

char	**map_check(char *map)
{
	char	**map_table;
	int		fd;

	fd = file_check(map);
	if (fd == -1)
	{
		ft_putstr_fd("wrong file !\n", STDERR_FILENO);
		return (NULL);
	}
	map_table = map_insert(fd);
	if (!check_format(map_table))
		exit_map_error(map_table);
	check_elem(map_table);
	if (check_map_format(map_table) == 0)
		exit_map_error(map_table);
	return (map_table);
}
