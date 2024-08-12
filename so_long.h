/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 19:35:19 by randrina          #+#    #+#             */
/*   Updated: 2024/08/12 15:57:52 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include "./minilibx-linux/mlx_int.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_map
{
	int	px;
	int	py;
	int	width;
	int	height;
	int	ex;
	int	ey;
}	t_map;

typedef struct s_data
{
	void	*mx_ptr;
	void	*wn_ptr;
	void	*img_wal;
	void	*img_way;
	void	*img_pl;
	void	*img_col;
	void	*img_ex;
	int		w;
	int		h;
	int		count;
	int		col_nbr;
	t_map	*map;
	char	**m_tab;
}	t_data;

int		ft_exit(t_data *data);
int		map_arg_check(char *map);
int		exit_check(char **map);
int		perso_check(char **map);
int		collec_check(char **map);
int		check_map_format(char **map);
int		collect_nbr(char **map);
char	*empty_check(int fd);
void	show_info(t_map *map);
void	free_struct(t_map *map_info);
void	insert_info(t_map *map_info, char **map);
t_map	*create_struct(void);
void	ft_check_road(char **map, t_map *map_info, char **map_cp);
void	exit_many_elem(char **map, char *elem);
void	exit_no_elem(char **map, char *elem);
void	exit_map_error(char **map);
void	tab_free(char **table);
char	**all_chek(char *input);
char	**map_check(char *map);
char	**map_cpy(char **map);
t_data	*create_data(t_map *map, char **map_tab);
void	display_wall(t_data *data, int x, int y);
void	display_collect(t_data *data, int x, int y);
void	window_gen(char **map, t_map *map_info);
void	display_other(t_data *data, int x, int y);
void	display_player(t_data *data, int x, int y);
void	window_disp(t_data *data);
int		manage_move(int keycode, t_data *data);

#endif
