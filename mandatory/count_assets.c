/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_assets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 00:28:09 by fbelkaid          #+#    #+#             */
/*   Updated: 2024/07/20 11:12:00 by fbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void	component_xy_position(char **map, int *cmp_posy, int *cmp_posx,
		int icon)
{
	*cmp_posy = 0;
	while (map[*cmp_posy] != NULL)
	{
		*cmp_posx = 0;
		while (map[*cmp_posy][*cmp_posx] != '\0')
		{
			if (map[*cmp_posy][*cmp_posx] == icon)
				return ;
			(*cmp_posx)++;
		}
		(*cmp_posy)++;
	}
}

void	flood_fill(char **tab, int x, int y)
{
	if (tab[y][x] == 'E')
	{
		tab[y][x] = 'o';
		return ;
	}
	if (tab[y][x] == '1' || tab[y][x] == '*')
		return ;
	tab[y][x] = '*';
	flood_fill(tab, x + 1, y);
	flood_fill(tab, x - 1, y);
	flood_fill(tab, x, y + 1);
	flood_fill(tab, x, y - 1);
}

void	check_path_to_exit(char **map_info, t_map *game)
{
	int	i;
	int	j;

	j = 0;
	flood_fill(game->mapcheck, game->player_x, game->player_y);
	(void)map_info;
	while (game->mapcheck[j])
	{
		i = 0;
		while (game->mapcheck[j][i])
		{
			if (game->mapcheck[j][i] == 'C' || game->mapcheck[j][i] == 'E')
			{
				free_map_on_error(map_info, "INVALID map akhiyiii !! \n");
				free_map_on_error(game->mapcheck, "INVALID map akhiyiii !! \n");
				exit(1);
			}
			i++;
		}
		j++;
	}
	free_map(game->mapcheck);
}

void	calc_width_height(char **map, t_info *inf)
{
	int	row_len;
	int	col_len;

	row_len = ft_strlen(map[0]) - 1;
	col_len = 0;
	while (map[col_len] != NULL)
		col_len++;
	inf->width = row_len * 60;
	inf->height = col_len * 60;
	if (inf->width > 5120 || inf->height > 2880)
		free_map_on_error(map, "The screen resolution is bigger, \
			performance suck");
}

void	count_collectibles(char **map, t_info *inf)
{
	int	col;
	int	row;

	col = 0;
	inf->collectibles = 0;
	while (map[col] != NULL)
	{
		row = 0;
		while (map[col][row] != '\0')
		{
			if (map[col][row] == 'C')
				inf->collectibles++;
			row++;
		}
		col++;
	}
}
