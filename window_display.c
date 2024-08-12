/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 05:08:44 by randrina          #+#    #+#             */
/*   Updated: 2024/08/12 16:37:11 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*create_data(t_map *map, char **map_tab)
{
	t_data	*data;

	data = (t_data *) malloc(sizeof(t_data));
	if (data == NULL)
		return (NULL);
	data->map = map;
	data->m_tab = map_tab;
	data->w = 0;
	data->h = 0;
	data->count = 0;
	data->col_nbr = collect_nbr(map_tab);
	data->mx_ptr = mlx_init();
	data->wn_ptr = mlx_new_window(data->mx_ptr, data->map->width * 50,
			data->map->height * 50, "so_long");
	return (data);
}

void	display_wall(t_data *data, int x, int y)
{
	data->img_wal = mlx_xpm_file_to_image(data->mx_ptr, "wall.xpm", &data->w,
			&data->h);
	mlx_put_image_to_window(data->mx_ptr, data->wn_ptr, data->img_wal, x, y);
	mlx_destroy_image(data->mx_ptr, data->img_wal);
}

static void	display_exit(t_data *data, int x, int y)
{
	data->img_ex = mlx_xpm_file_to_image(data->mx_ptr, "exit.xpm", &data->w,
			&data->h);
	mlx_put_image_to_window(data->mx_ptr, data->wn_ptr, data->img_ex, x, y);
	mlx_destroy_image(data->mx_ptr, data->img_ex);
}

static void	display_way(t_data *data, int x, int y)
{
	data->img_way = mlx_xpm_file_to_image(data->mx_ptr, "way.xpm", &data->w,
			&data->h);
	mlx_put_image_to_window(data->mx_ptr, data->wn_ptr, data->img_way, x, y);
	mlx_destroy_image(data->mx_ptr, data->img_way);
}

void	display_other(t_data *data, int x, int y)
{
	if (data->m_tab[y / 50][x / 50] == 'E')
		display_exit(data, x, y);
	else if (data->m_tab[y / 50][x / 50] == 'C')
		display_collect(data, x, y);
	else if (data->m_tab[y / 50][x / 50] == 'P')
		display_player(data, x, y);
	else
		display_way(data, x, y);
}
