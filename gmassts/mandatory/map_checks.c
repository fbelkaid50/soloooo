/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:14:53 by fbelkaid          #+#    #+#             */
/*   Updated: 2024/07/20 11:38:58 by fbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void	player_position(t_map *map_info, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				map_info->player_x = j;
				map_info->player_y = i;
			}
			j++;
		}
		i++;
	}
}

void	initialize_and_check_map(t_map *map_info, char **map, char *map_file)
{
	player_position(map_info, map);
	map_info->collectible = 0;
	map_info->exit = 0;
	map_info->size_map = map_size(map_file);
	check_lines(map);
	check_walls(map[0]);
	check_walls(map[map_info->size_map - 1]);
	check_columns(map);
}

void	process_map_element(t_map *map_info, char **map, int i, int j)
{
	if (map[i][j] == 'P')
	{
		check_surroundings(j, i, map);
		map_info->player++;
	}
	if (map[i][j] == 'C')
	{
		check_surroundings(j, i, map);
		map_info->collectible++;
	}
	if (map[i][j] == 'E')
	{
		check_surroundings(j, i, map);
		map_info->exit++;
	}
	if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != '\n'
		&& map[i][j] != 'P' && map[i][j] != 'C' && map[i][j] != 'E')
	{
		ft_putstr_fd("Error: Map must have only 0, 1, P, C, E\n", 2);
		exit(1);
	}
}

void	process_map_elements(t_map *map_info, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			process_map_element(map_info, map, i, j);
			j++;
		}
		i++;
	}
	check_errors(map_info);
}

void	check_map(char **map, t_map *map_info, char *map_file)
{
	initialize_and_check_map(map_info, map, map_file);
	check_path_to_exit(map, map_info);
	process_map_elements(map_info, map);
}
