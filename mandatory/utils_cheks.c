/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cheks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 23:50:52 by fbelkaid          #+#    #+#             */
/*   Updated: 2024/07/22 22:29:25 by fbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void	check_lines(char **map)
{
	int	i;
	int	line_length;
	int	current_line_length;

	i = 0;
	line_length = ft_strlen(map[0]);
	if (map[0][line_length - 1] == '\n')
		line_length--;
	while (map[i])
	{
		current_line_length = 0;
		while (map[i][current_line_length] != '\0'
			&& map[i][current_line_length] != '\n')
			current_line_length++;
		if (current_line_length != line_length)
		{
			ft_putstr_fd("Error: Map must have the same length for each line ",
				2);
			free_map(map);
			exit(1);
		}
		i++;
	}
}

void	check_surroundings(int x, int y, char **map)
{
	if (map[y - 1][x] == '1' && map[y + 1][x] == '1' && map[y][x - 1] == '1'
		&& map[y][x + 1] == '1')
		free_map_on_error(map, "Error: ach had l7ebss !!!\n");
	else if (map[y - 1][x] == 'E' && map[y + 1][x] == '1' && map[y][x
		- 1] == '1' && map[y][x + 1] == '1')
		free_map_on_error(map, "Error: ach had l7ebss !!!\n");
	else if (map[y - 1][x] == '1' && map[y + 1][x] == 'E' && map[y][x
		- 1] == '1' && map[y][x + 1] == '1')
		free_map_on_error(map, "Error: ach had l7ebss !!!\n");
	else if (map[y - 1][x] == '1' && map[y + 1][x] == '1' && map[y][x
		- 1] == 'E' && map[y][x + 1] == '1')
		free_map_on_error(map, "Error: ach had l7ebss !!!\n");
	else if (map[y - 1][x] == '1' && map[y + 1][x] == '1' && map[y][x
		- 1] == '1' && map[y][x + 1] == 'E')
		free_map_on_error(map, "Error: ach had l7ebss !!!\n");
	return ;
}

void	check_walls(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == '1' || map[i] == '\n')
			i++;
		else
		{
			ft_putstr_fd("Error: Map must have only 1 and 0\n", 2);
			exit(1);
		}
	}
	return ;
}

void	check_errors(t_map *map_info)
{
	if (map_info->player != 1)
	{
		ft_putstr_fd("Error: Map must have one player\n", 2);
		exit(1);
	}
	if (map_info->collectible < 1)
	{
		ft_putstr_fd("Error: Map must have at least one collectible\n", 2);
		exit(1);
	}
	if (map_info->exit != 1)
	{
		ft_putstr_fd("Error: Map must have one exit\n", 2);
		exit(1);
	}
}

void	check_columns(char **map)
{
	int	i;
	int	len;

	i = 0;
	while (map[i] != NULL)
	{
		len = ft_strlen(map[i]) - 1;
		if (map[i][0] != '1')
		{
			ft_putstr_fd("Error 2: Map must be surrounded by walls !!", 2);
			free_map(map);
			exit(1);
		}
		if (map[i][len - 1] != '1')
		{
			ft_putstr_fd("Error 3: Map must be surrounded by walls !!", 2);
			free_map(map);
			exit(1);
		}
		i++;
	}
}
