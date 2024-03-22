/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control_extra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knarman <knarman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 06:06:01 by knarman          #+#    #+#             */
/*   Updated: 2024/03/22 01:59:51 by knarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_control(void)
{
	int	fd_exit;
	int	fd_tile;
	int	fd_wall;
	int	fd_collect;

	fd_exit = open("./xpm/exit.xpm", O_RDWR);
	fd_tile = open("./xpm/tile.xpm", O_RDWR);
	fd_wall = open("./xpm/wall.xpm", O_RDWR);
	fd_collect = open("./xpm/collect.xpm", O_RDWR);
	if (fd_exit <= 0 || fd_tile <= 0 || fd_wall <= 0 || fd_collect <= 0)
	{
		write(1, "Missing XPM File\n", 18);
		close(fd_exit);
		close(fd_tile);
		close(fd_wall);
		close(fd_collect);
		exit(1);
	}
	close(fd_exit);
	close(fd_tile);
	close(fd_wall);
	close(fd_collect);
}

void	xpm_control_2(void)
{
	int	fd_up;
	int	fd_down;
	int	fd_left;
	int	fd_right;
	int	fd_enemy;

	fd_up = open("./xpm/up.xpm", O_RDWR);
	fd_enemy = open("./xpm/enemy.xpm", O_RDWR);
	fd_down = open("./xpm/down.xpm", O_RDWR);
	fd_left = open("./xpm/left.xpm", O_RDWR);
	fd_right = open("./xpm/right.xpm", O_RDWR);
	if (fd_down <= 0 || fd_up <= 0 || fd_left <= 0 || fd_right <= 0 || fd_enemy <= 0)
	{
		write(1, "Missing XPM File\n", 18);
		close(fd_down);
		close(fd_up);
		close(fd_left);
		close(fd_right);
		close(fd_enemy);
		exit(1);
	}
	close(fd_down);
	close(fd_up);
	close(fd_left);
	close(fd_right);
	close(fd_enemy);
}

static int	path_finder(t_window *pnc, int x, int y)
{
	if (pnc->map->clone_map[y][x] == '1')
		return (1);
	if (pnc->map->clone_map[y][x] == 'N')
		return (1);
	if (pnc->map->clone_map[y][x] == 'C')
	{
		pnc->coin += 1;
	}
	if (pnc->map->clone_map[y][x] == 'E')
		pnc->exit += 1;
	if (pnc->map->clone_map[y][x] != 'P' && pnc->map->clone_map[y][x] != '0'
		&& pnc->map->clone_map[y][x] == 'N')
	{
		ft_putstr_fd("Error: Undefined Char", 2);
		close_game(pnc);
	}
	pnc->map->clone_map[y][x] = '1';
	path_finder(pnc, x - 1, y);
	path_finder(pnc, x, y - 1);
	path_finder(pnc, x + 1, y);
	path_finder(pnc, x, y + 1);
	return (1);
}

void	path_finder_control(t_window *pnc)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	path_finder(pnc, pnc->chr->x, pnc->chr->y);
	if (pnc->coin != pnc->map->coin_cnt)
		(ft_putstr_fd("Error: Unreachable coin", 2), close_game(pnc));
	if (pnc->exit != 1)
		(ft_putstr_fd("Error: Unreachable exit", 2), close_game(pnc));
}
