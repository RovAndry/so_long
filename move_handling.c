/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:38:25 by randrina          #+#    #+#             */
/*   Updated: 2024/08/12 16:36:18 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_top(t_data *data)
{
	int	x;
	int	y;

	x = data->map->px;
	y = data->map->py;
	if (data->m_tab[y - 1][x] == 'C')
            data->col_nbr = data->col_nbr - 1;
	if (data->m_tab[y -1][x] != '1' && y > 0)
	{
		data->m_tab[y][x] = '0';
		data->map->py = data->map->py - 1;
		y = data->map->py;
		data->m_tab[y][x] = 'P';
		display_other(data, x * 50, (y + 1) * 50);
		display_other(data, x * 50, y * 50);
		data->count = data->count + 1;
		ft_putnbr_fd(data->count, 1);
		ft_putchar_fd('\n', 1);
		if (data->col_nbr == 0 && x == data->map->ex && y == data->map->ey)
			ft_exit(data);
	}
}

static void	move_down(t_data *data)
{
	int	x;
	int	y;

	x = data->map->px;
	y = data->map->py;
	if (data->m_tab[y + 1][x] == 'C')
            data->col_nbr = data->col_nbr - 1;
	if (data->m_tab[y + 1][x] != '1' && y < data->map->height - 2)
	{
		data->m_tab[y][x] = '0';
		data->map->py = data->map->py + 1;
		y = data->map->py;
		data->m_tab[y][x] = 'P';
		display_other(data, x * 50, (y - 1) * 50);
		display_other(data, x * 50, y *50);
		data->count = data->count + 1;
		ft_putnbr_fd(data->count, 1);
		ft_putchar_fd('\n', 1);
		if (data->col_nbr == 0 && x == data->map->ex && y == data->map->ey)
            ft_exit(data);
	}
}

static void	move_left(t_data *data)
{
	int	x;
	int	y;

	x = data->map->px;
	y = data->map->py;
	if (data->m_tab[y][x - 1] == 'C')
            data->col_nbr = data->col_nbr - 1;
	if (data->m_tab[y][x -1] != '1' && x > 0)
	{
		data->m_tab[y][x] = '0';
		data->map->px = data->map->px - 1;
		x = data->map->px;
		data->m_tab[y][x] = 'P';
		display_other(data, (x + 1) * 50, y * 50);
		display_other(data, x * 50, y * 50);
		data->count = data->count + 1;
		ft_putnbr_fd(data->count, 1);
		ft_putchar_fd('\n', 1);
		if (data->col_nbr == 0 && x == data->map->ex && y == data->map->ey)
            ft_exit(data);
	}
}

static void	move_right(t_data *data)
{
	int	x;
	int	y;

	x = data->map->px;
	y = data->map->py;
	if (data->m_tab[y][x + 1] == 'C')
            data->col_nbr = data->col_nbr - 1;
	if (data->m_tab[y][ x + 1] != '1' && x < data->map->width - 2)
	{
		data->m_tab[y][x] = '0';
		data->map->px = data->map->px + 1;
		x = data->map->px;
		data->m_tab[y][x] = 'P';
		display_other(data, (x - 1) * 50, y * 50);
		display_other(data, x * 50, y * 50);
		data->count = data->count + 1;
		ft_putnbr_fd(data->count, 1);
		ft_putchar_fd('\n', 1);
		if (data->col_nbr == 0 && x == data->map->ex && y == data->map->ey)
            ft_exit(data);
	}
}

int	manage_move(int keycode, t_data *data)
{
	if (keycode == 'w')
		move_top(data);
	else if (keycode == 's')
		move_down(data);
	else if (keycode == 'a')
		move_left(data);
	else if (keycode == 'd')
		move_right(data);
	if (data->col_nbr == 0)
		display_exit(data, data->map->ex * 50, data->map->ey * 50);
	return (1);
}
