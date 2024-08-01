/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 19:35:19 by randrina          #+#    #+#             */
/*   Updated: 2024/08/01 13:37:38 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_map
{
	int	px;
	int	py;
	int	width;
	int	height;
}	t_map;

# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include "./minilibx-linux/mlx_int.h"
# include <fcntl.h>
# include <stdio.h>

int		map_arg_check(char *map);
int		exit_check(char **map);
int		perso_check(char **map);
int		collec_check(char **map);
int		check_map_format(char **map);

void	free_struct(t_map *map_info);
void	insert_surf(t_map *map_info, char **map);
void	insert_play_pos(t_map *map_info, char **map);
void	insert_info(t_map *map_info, char **map);
t_map	*create_struct(void);

void	show_map(char **map);
void	exit_many_elem(char **map, char *elem);
void	exit_no_elem(char **map, char *elem);
void	exit_map_error(char **map);
void	tab_free(char **table);
char	**map_check(char *map);

#endif
