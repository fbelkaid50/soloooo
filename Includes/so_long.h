/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:43:56 by fbelkaid          #+#    #+#             */
/*   Updated: 2024/07/22 10:36:31 by fbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../Includes/get_next_line.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	int		player;
	int		collectible;
	int		exit;
	int		size_map;
	int		player_x;
	int		player_y;
	char	**mapcheck;
}			t_map;

typedef struct s_info
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	**map;
	char	*path_player;
	char	*path_exit;
	char	*path_collectible;
	char	*path_wall;
	char	*path_bg;
	int		collectibles;
	int		width;
	int		height;
	int		p_positionx;
	int		p_positiony;
	int		d_positionx;
	int		d_positiony;
	int		count_moves;
	int		xpm_width;
	int		xpm_height;
}			t_info;

char		*ft_strstr(char *str, char *to_find, int len);
char		**ft_read_map(char *map_file);
void		play_game(char **game);
void		free_map_on_error(char **map, char *message);
void		check_walls(char *map);
void		free_map(char **map);
int			ft_strlen(char *str);
void		ft_putstr_fd(char *str, int fd);
void		check_surroundings(int x, int y, char **map);
void		destroy_all(t_info *inf, char *message, int out);
void		move_player(int keycode, t_info *inf);
int			key_press(int keycode, t_info *inf);
int			close_window(t_info *inf);
void		check_lines(char **map);
void		put_image_to_window(t_info *inf, int x, int y);
void		load_xpm_image(char icon, t_info *inf, int x, int y);
void		draw_map(char **map, t_info *inf);
void		check_errors(t_map *map_info);
void		check_columns(char **map);
void		calc_width_height(char **map, t_info *inf);
int			key_press(int keycode, t_info *inf);
void		draw_map(char **map, t_info *inf);
void		initialize(char **map, t_info *inf);
void		ft_putnbr_fd(int n, int fd);
void		move_right(t_info *info);
void		initialize_paths(t_info *inf);
void		play_game(char **map);
void		move_up(t_info *inf);
void		count_collectibles(char **map, t_info *inf);
void		move_player(int key_code, t_info *game);
void		component_xy_position(char **map, int *cmp_posy, int *cmp_posx,
				int icon);
void		initialize(char **map, t_info *inf);
void		initialize_paths(t_info *inf);
void		move_down(t_info *inf);
void		move_left(t_info *inf);
int			close_window(t_info *inf);
void		put_assets(t_info *game, char **map);
void		destroy_all(t_info *game, char *message, int out);
void		put_xpm_image(char place, t_info *game, int column, int height);
void		put_image(t_info *game, int x, int y);
void		count_collectibles(char **map, t_info *inf);
void		calcule_width_height(t_info *inf);
void		initialize_paths(t_info *game);
int			ft_strlen(char *str);
void		check_map(char **map, t_map *game, char *map_file);
void		player_position(t_map *map_info, char **map);
void		flood_fill(char **tab, int x, int y);
int			map_size(char *map_file);
void		check_path_to_exit(char **map_info, t_map *game);

#endif
