/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:43:05 by fbelkaid          #+#    #+#             */
/*   Updated: 2024/07/22 22:33:01 by fbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

int	map_size(char *map_file)
{
	int		size;
	int		fd;
	char	*line_read;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Check if the file exist", 2);
		exit(1);
	}
	line_read = get_next_line(fd);
	if (line_read == NULL)
	{
		ft_putstr_fd("Check if the file is empty", 2);
		exit(1);
	}
	size = 0;
	while (line_read != NULL)
	{
		free(line_read);
		line_read = get_next_line(fd);
		size++;
	}
	close(fd);
	return (size);
}

char	**ft_read_map(char *map_file)
{
	char	**map;
	char	*line_read;
	int		fd;
	int		row;

	map = malloc((map_size(map_file) + 1) * sizeof(char *));
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
	{
		free(map);
		exit(1);
	}
	if (map)
	{
		row = 0;
		line_read = get_next_line(fd);
		while (line_read != NULL)
		{
			map[row++] = line_read;
			line_read = get_next_line(fd);
		}
		map[row] = NULL;
	}
	close(fd);
	return (map);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;

	tmp = 0;
	while (*s)
	{
		if (*s == (unsigned char)c)
			tmp = (char *)s;
		++s;
	}
	if (!(char)c)
		tmp = ((char *)s);
	return (tmp);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	main(int ac, char **av)
{
	char	**map;
	t_map	*game;

	if (ac == 2)
	{
		if (ft_strcmp(".ber", ft_strrchr(av[1], '.')) != 0
			&& ft_strlen(ft_strrchr(av[1], '.')) != 4)
		{
			ft_putstr_fd("Extention khasha tkon .ber", 2);
			exit(1);
		}
		map = ft_read_map(av[1]);
		game = malloc(sizeof(t_map));
		if (game == NULL)
			free_map_on_error(map, "Error d malloc \n");
		game->mapcheck = ft_read_map(av[1]);
		if (map)
		{
			check_map(map, game, av[1]);
			play_game(map);
		}
	}
	return (0);
}
