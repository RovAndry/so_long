/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_display_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 06:00:12 by randrina          #+#    #+#             */
/*   Updated: 2024/08/12 16:30:41 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_collect(t_data *data, int x, int y)
{
	data->img_col = mlx_xpm_file_to_image(data->mx_ptr, "collect.xpm", &data->w,
			&data->h);
	mlx_put_image_to_window(data->mx_ptr, data->wn_ptr, data->img_col, x, y);
	mlx_destroy_image(data->mx_ptr, data->img_col);
}

void	display_player(t_data *data, int x, int y)
{
	data->img_pl = mlx_xpm_file_to_image(data->mx_ptr, "player.xpm", &data->w,
			&data->h);
	mlx_put_image_to_window(data->mx_ptr, data->wn_ptr, data->img_pl, x, y);
	mlx_destroy_image(data->mx_ptr, data->img_pl);
}

void	window_disp(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map->height * 50)
	{
		x = 0;
		while (x < data->map->width * 50)
		{
			if (data->m_tab[y / 50][x / 50] == '1')
				display_wall(data, x, y);
			else
				display_other(data, x, y);
			x += 50;
		}
		y += 50;
	}
}
