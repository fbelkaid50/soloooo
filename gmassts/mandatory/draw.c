/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 00:30:45 by fbelkaid          #+#    #+#             */
/*   Updated: 2024/07/19 12:20:32 by fbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void	destroy_all(t_info *inf, char *message, int out)
{
	if (inf->img_ptr != NULL)
		mlx_destroy_image(inf->mlx_ptr, inf->img_ptr);
	ft_putstr_fd(message, out);
	if (inf->win_ptr != NULL)
		mlx_destroy_window(inf->mlx_ptr, inf->win_ptr);
	free_map(inf->map);
	exit(0);
}

void	put_image_to_window(t_info *inf, int x, int y)
{
	if (inf->img_ptr == NULL)
		destroy_all(inf, "Check the path if its correct", 2);
	else if (inf->xpm_width != 60 || inf->xpm_height != 60)
		destroy_all(inf, "the xpm file not respecting the right dimensions", 2);
	mlx_put_image_to_window(inf->mlx_ptr, inf->win_ptr, inf->img_ptr, x, y);
	mlx_destroy_image(inf->mlx_ptr, inf->img_ptr);
	inf->img_ptr = NULL;
}

void	load_xpm_image(char icon, t_info *inf, int x, int y)
{
	if (icon == 'P' || icon == 'E' || icon == 'C')
	{
		inf->img_ptr = mlx_xpm_file_to_image(inf->mlx_ptr, inf->path_bg,
				&(inf->xpm_width), &(inf->xpm_height));
		put_image_to_window(inf, x, y);
	}
	if (icon == 'P')
		inf->img_ptr = mlx_xpm_file_to_image(inf->mlx_ptr, inf->path_player,
				&(inf->xpm_width), &(inf->xpm_height));
	else if (icon == '1')
		inf->img_ptr = mlx_xpm_file_to_image(inf->mlx_ptr, inf->path_wall,
				&(inf->xpm_width), &(inf->xpm_height));
	else if (icon == 'C')
		inf->img_ptr = mlx_xpm_file_to_image(inf->mlx_ptr,
				inf->path_collectible, &(inf->xpm_width), &(inf->xpm_height));
	else if (icon == 'E')
		inf->img_ptr = mlx_xpm_file_to_image(inf->mlx_ptr, inf->path_exit,
				&(inf->xpm_width), &(inf->xpm_height));
	else
		inf->img_ptr = mlx_xpm_file_to_image(inf->mlx_ptr, inf->path_bg,
				&(inf->xpm_width), &(inf->xpm_height));
	put_image_to_window(inf, x, y);
}

void	draw_map(char **map, t_info *inf)
{
	int	col;
	int	row;
	int	x;
	int	y;

	col = 0;
	y = 0;
	while (y < inf->height)
	{
		row = 0;
		x = 0;
		while (x < inf->width)
		{
			load_xpm_image(map[col][row], inf, x, y);
			x += 60;
			row++;
		}
		y += 60;
		col++;
	}
}
