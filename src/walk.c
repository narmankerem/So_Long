/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knarman <knarman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 03:36:34 by knarman          #+#    #+#             */
/*   Updated: 2024/03/22 11:23:14 by knarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	putchr(t_window *pnc, int keycode)
{
	if (keycode == 2)
		pnc->chr->chr_current = pnc->chr->chr_right;
	if (keycode == 0)
		pnc->chr->chr_current = pnc->chr->chr_left;
	if (keycode == 13)
		pnc->chr->chr_current = pnc->chr->chr_back;
	if (keycode == 1)
		pnc->chr->chr_current = pnc->chr->chr_front;
}

int	enemymove(t_window *pnc)
{
	static int	wall_check = 0;
	static int	i;

	i = 0;
	render_map(pnc);
	if (++i == 15)
		i = 0;
	if (pnc->map->mappin[pnc->enemy->y / PIXEL][(pnc->enemy->x / PIXEL)
		- 1] == '1')
		wall_check = 1;
	if (pnc->map->mappin[pnc->enemy->y / PIXEL][(pnc->enemy->x / PIXEL)
		+ 1] == '1')
		wall_check = 0;
	if (wall_check && pnc->map->mappin[pnc->enemy->y / PIXEL][pnc->enemy->x
		/ PIXEL] != '1')
		pnc->enemy->x++;
	else if (!wall_check && pnc->map->mappin[pnc->enemy->y
		/ PIXEL][pnc->enemy->x / PIXEL] != '1')
		pnc->enemy->x--;
	if (pnc->map->mappin[pnc->enemy->y / PIXEL][pnc->enemy->x
		/ PIXEL] == pnc->map->mappin[pnc->chr->y / PIXEL][pnc->chr->x / PIXEL])
	{
		write(1, "GAME OVER\n", 10);
		close_game_mlx(pnc);
	}
	return (0);
}

static void	move_player(t_window *pnc, int side, int x, int y)
{
	if (pnc->map->mappin[y / PIXEL][x / PIXEL] != '1' && pnc->map->mappin[y
		/ PIXEL][x / PIXEL] != 'N')
	{
		putchr(pnc, side);
		pnc->chr->point += 1;
		if (pnc->map->mappin[y / PIXEL][x / PIXEL] == 'C')
			pnc->map->coin_cnt -= 1;
		pnc->map->mappin[pnc->chr->y / PIXEL][pnc->chr->x / PIXEL] = '0';
		pnc->map->mappin[pnc->map->exit_y / PIXEL][pnc->map->exit_x
			/ PIXEL] = 'E';
		pnc->map->mappin[y / PIXEL][x / PIXEL] = 'P';
		pnc->map->mappin[pnc->enemy->y / PIXEL][pnc->enemy->x / PIXEL] = 'N';
		ft_putnbr(pnc->chr->point);
		write(1, "\n", 1);
	}
	if (pnc->map->coin_cnt == 0 && pnc->map->mappin[pnc->map->exit_y
		/ PIXEL][pnc->map->exit_x / PIXEL] == pnc->map->mappin[y / PIXEL][x
		/ PIXEL])
	{
		pnc->chr->point += 1;
		ft_putnbr(pnc->chr->point);
		write(1, "\nWin", 4);
		close_game_mlx(pnc);
	}
	if (pnc->map->mappin[pnc->enemy->y / PIXEL][pnc->enemy->x
		/ PIXEL] == pnc->map->mappin[y / PIXEL][x / PIXEL])
	{
		pnc->chr->point += 1;
		ft_putnbr(pnc->chr->point);
		write(1, "\nLose", 5);
		close_game_mlx(pnc);
	}
}

int	walk(int keycode, void *param)
{
	t_window *pnc;

	pnc = param;
	mlx_clear_window(pnc->mlx, pnc->win);

	if (keycode == 53)
		close_game(pnc);
	if (keycode == 2)
		move_player(pnc, keycode, pnc->chr->x + PIXEL, pnc->chr->y);
	if (keycode == 0)
		move_player(pnc, keycode, pnc->chr->x - PIXEL, pnc->chr->y);
	if (keycode == 13)
		move_player(pnc, keycode, pnc->chr->x, pnc->chr->y - PIXEL);
	if (keycode == 1)
		move_player(pnc, keycode, pnc->chr->x, pnc->chr->y + PIXEL);

	render_map(pnc);
	return (keycode);
}