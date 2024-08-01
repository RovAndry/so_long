
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 08:04:33 by randrina          #+#    #+#             */
/*   Updated: 2024/07/31 19:24:17 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	/*void	*mlx_ptr;
	void	*win_ptr;
	int 	x;
	int		y;*/
	char 	**map;
	t_map	*maps;

	if (argc == 2)
	{
		map = map_check(argv[1]);
		if (map != NULL)
		{
			maps = create_struct();
			insert_info(maps, map);
			show_info(maps);
			show_map(map);
			printf("\n\n");
			ft_check_road(map, maps);
			tab_free(map);
		}
	}	
	/*mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "window");
	y = 0;
	while (y < 500)
	{
		x = 0;
		while (x < 500)
		{
			if (x % 2 == 0 && y % 2 == 0)
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xffd700);
			else
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xff00ff);
			x ++;
		}
		y ++;
	}
	mlx_loop(mlx_ptr);*/
	return (0);
}
