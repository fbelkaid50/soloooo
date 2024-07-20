/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 00:26:12 by fbelkaid          #+#    #+#             */
/*   Updated: 2024/07/20 11:39:47 by fbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void	move_right(t_info *info)
{
	if (info->map[info->p_positiony][info->p_positionx + 1] == 'C')
		info->collectibles--;
	if (info->map[info->p_positiony][info->p_positionx + 1] == 'C'
		|| info->map[info->p_positiony][info->p_positionx + 1] == '0')
	{
		info->map[info->p_positiony][info->p_positionx + 1] = 'P';
		info->map[info->p_positiony][info->p_positionx] = '0';
		info->p_positionx++;
		write(1, "The moves: ", 11);
		ft_putnbr_fd(++(info->count_moves), 1);
		write(1, "\n", 1);
	}
	else if (info->map[info->p_positiony][info->p_positionx + 1] == 'E'
		&& info->collectibles == 0)
		info->p_positionx++;
	info->path_player = "./solonggpics/AnyConv.com__player.xpm";
}

void	move_up(t_info *inf)
{
	if (inf->map[inf->p_positiony - 1][inf->p_positionx] == 'C')
		inf->collectibles--;
	if (inf->map[inf->p_positiony - 1][inf->p_positionx] == 'C'
		|| inf->map[inf->p_positiony - 1][inf->p_positionx] == '0')
	{
		inf->map[inf->p_positiony - 1][inf->p_positionx] = 'P';
		inf->map[inf->p_positiony][inf->p_positionx] = '0';
		inf->p_positiony--;
		write(1, "The moves: ", 11);
		ft_putnbr_fd(++(inf->count_moves), 1);
		write(1, "\n", 1);
	}
	else if (inf->map[inf->p_positiony - 1][inf->p_positionx] == 'E'
		&& inf->collectibles == 0)
		inf->p_positiony--;
}

void	move_left(t_info *inf)
{
	if (inf->map[inf->p_positiony][inf->p_positionx - 1] == 'C')
		inf->collectibles--;
	if (inf->map[inf->p_positiony][inf->p_positionx - 1] == 'C'
		|| inf->map[inf->p_positiony][inf->p_positionx - 1] == '0')
	{
		inf->map[inf->p_positiony][inf->p_positionx - 1] = 'P';
		inf->map[inf->p_positiony][inf->p_positionx] = '0';
		inf->p_positionx--;
		write(1, "The moves: ", 11);
		ft_putnbr_fd(++(inf->count_moves), 1);
		write(1, "\n", 1);
	}
	else if (inf->map[inf->p_positiony][inf->p_positionx - 1] == 'E'
		&& inf->collectibles == 0)
		inf->p_positionx--;
	inf->path_player = "./solonggpics/AnyConv.com__player.xpm";
}

void	move_down(t_info *inf)
{
	if (inf->map[inf->p_positiony + 1][inf->p_positionx] == 'C')
		inf->collectibles--;
	if (inf->map[inf->p_positiony + 1][inf->p_positionx] == 'C'
		|| inf->map[inf->p_positiony + 1][inf->p_positionx] == '0')
	{
		inf->map[inf->p_positiony + 1][inf->p_positionx] = 'P';
		inf->map[inf->p_positiony][inf->p_positionx] = '0';
		inf->p_positiony++;
		write(1, "The moves: ", 11);
		ft_putnbr_fd(++(inf->count_moves), 1);
		write(1, "\n", 1);
	}
	else if ((inf->map[inf->p_positiony + 1][inf->p_positionx] == 'E'
		&& inf->collectibles == 0))
		inf->p_positiony++;
}

void	move_player(int keycode, t_info *inf)
{
	if (keycode == 124)
		move_right(inf);
	else if (keycode == 126)
		move_up(inf);
	else if (keycode == 123)
		move_left(inf);
	else if (keycode == 125)
		move_down(inf);
	else if (keycode == 53)
		destroy_all(inf, "You exit the game", 1);
}
