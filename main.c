/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 09:57:55 by randrina          #+#    #+#             */
/*   Updated: 2024/08/13 08:48:48 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(char **str)
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

int	ft_exit(t_data *data)
{
	mlx_destroy_window(data->mx_ptr, data->wn_ptr);
	mlx_destroy_display(data->mx_ptr);
	free(data->mx_ptr);
	ft_free(data->m_tab);
	free(data->map);
	free(data);
	exit(0);
	return (0);
}

void	window_gen(char **map, t_map *map_info)
{
	t_data	*data;

	data = create_data(map_info, map);
	window_disp(data);
	mlx_key_hook(data->wn_ptr, manage_move, data);
	mlx_hook(data->wn_ptr, 17, 0, ft_exit, data);
	mlx_loop(data->mx_ptr);
	free(data);
}

int	main(int argc, char **argv)
{
	char	**map;
	t_map	*map_info;

	if (argc == 2)
	{
		map = all_chek(argv[1]);
		map_info = create_struct();
		insert_info(map_info, map);
		window_gen(map, map_info);
	}
	return (0);
}
