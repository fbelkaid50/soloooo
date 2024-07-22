/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 22:13:21 by fbelkaid          #+#    #+#             */
/*   Updated: 2024/07/22 22:14:29 by fbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

int	key_press(int keycode, t_info *inf)
{
	int	prev_pos_x;
	int	prev_pos_y;

	prev_pos_x = inf->p_positionx;
	prev_pos_y = inf->p_positiony;
	move_player(keycode, inf);
	if (inf->collectibles == 0)
		inf->path_exit = "./textures/AnyConv.com__exit.xpm";
	if (inf->collectibles == 0
		&& inf->map[inf->p_positiony][inf->p_positionx] == 'E')
		destroy_all(inf, "\t\t\t\t\tYOU WIN  !!\t\t\t\t\t", 1);
	load_xpm_image(inf->map[inf->d_positiony][inf->d_positionx], inf,
		inf->d_positionx * 60, inf->d_positiony * 60);
	load_xpm_image(inf->map[prev_pos_y][prev_pos_x], inf, prev_pos_x * 60,
		prev_pos_y * 60);
	load_xpm_image(inf->map[inf->p_positiony][inf->p_positionx], inf,
		inf->p_positionx * 60, inf->p_positiony * 60);
	return (0);
}

int	close_window(t_info *inf)
{
	destroy_all(inf, "You destroyed the game", 1);
	return (0);
}

void	initialize_paths(t_info *inf)
{
	inf->path_player = "./textures/AnyConv.com__player.xpm";
	inf->path_exit = "./textures/AnyConv.com__exit.xpm";
	inf->path_collectible = "./textures/AnyConv.com__collectbles.xpm";
	inf->path_wall = "./textures/AnyConv.com__wall.xpm";
	inf->path_bg = "./textures/AnyConv.com__ground.xpm";
}

void	initialize(char **map, t_info *inf)
{
	inf->map = map;
	calc_width_height(inf->map, inf);
	inf->mlx_ptr = mlx_init();
	inf->img_ptr = NULL;
	inf->win_ptr = NULL;
	if (inf->mlx_ptr == NULL)
		destroy_all(inf, "Connection failed to X server", 2);
	inf->win_ptr = mlx_new_window(inf->mlx_ptr, inf->width, inf->height,
			"so_long");
	if (inf->win_ptr == NULL)
		destroy_all(inf, "Problem initializing the window", 2);
	initialize_paths(inf);
	draw_map(inf->map, inf);
	component_xy_position(inf->map, &(inf->p_positiony), &(inf->p_positionx),
		'P');
	component_xy_position(inf->map, &(inf->d_positiony), &(inf->d_positionx),
		'E');
	count_collectibles(inf->map, inf);
	inf->count_moves = 0;
}

void	play_game(char **map)
{
	t_info	inf;

	initialize(map, &inf);
	mlx_hook(inf.win_ptr, 2, 0, key_press, &inf);
	mlx_hook(inf.win_ptr, 17, 0, close_window, &inf);
	mlx_loop(inf.mlx_ptr);
}
