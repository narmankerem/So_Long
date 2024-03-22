/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knarman <knarman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 04:17:40 by knarman          #+#    #+#             */
/*   Updated: 2024/03/22 01:58:30 by knarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_img(t_window *pnc, int x, int y)
{
	pnc->height = pnc->map->h * PIXEL;
	pnc->width = pnc->map->w * PIXEL;
	pnc->mlx = mlx_init();
	pnc->win = mlx_new_window(pnc->mlx, pnc->width, pnc->height,
			"Mukemmel Oyun");
	pnc->chr->x = 0;
	pnc->chr->y = 0;
	pnc->enemy->x = 0;
	pnc->enemy->y = 0;
	pnc->chr->point = 0;
	pnc->enemy->enemy_right = mlx_xpm_file_to_image(pnc->mlx, "./xpm/enemy.xpm", &x,
			&y);
	pnc->chr->chr_front = mlx_xpm_file_to_image(pnc->mlx, "./xpm/front.xpm", &x,
			&y);
	pnc->chr->chr_back = mlx_xpm_file_to_image(pnc->mlx, "./xpm/back.xpm", &x,
			&y);
	pnc->chr->chr_right = mlx_xpm_file_to_image(pnc->mlx, "./xpm/right.xpm", &x,
			&y);
	pnc->chr->chr_left = mlx_xpm_file_to_image(pnc->mlx, "./xpm/left.xpm", &x,
			&y);
	pnc->chr->chr_current = pnc->chr->chr_front;
	pnc->img_bg = mlx_xpm_file_to_image(pnc->mlx, "./xpm/tile.xpm", &x, &y);
	pnc->wall_bg = mlx_xpm_file_to_image(pnc->mlx, "./xpm/wall.xpm", &x, &y);
	pnc->coin_bg = mlx_xpm_file_to_image(pnc->mlx, "./xpm/collect.xpm", &x, &y);
	pnc->exit_bg = mlx_xpm_file_to_image(pnc->mlx, "./xpm/exit.xpm", &x, &y);
}

static void	put_img(char c, t_window *pnc, int x, int y)
{
	mlx_put_image_to_window(pnc->mlx, pnc->win, pnc->img_bg, x, y);
	if (c == 'P')
	{
		pnc->chr->x = x;
		pnc->chr->y = y;
		mlx_put_image_to_window(pnc->mlx, pnc->win, pnc->chr->chr_current, x,
			y);
	}
	if (c == '1')
		mlx_put_image_to_window(pnc->mlx, pnc->win, pnc->wall_bg, x, y);
	if (c == 'C')
		mlx_put_image_to_window(pnc->mlx, pnc->win, pnc->coin_bg, x, y);
	if (c == 'E')
	{
		pnc->map->exit_x = x;
		pnc->map->exit_y = y;
		mlx_put_image_to_window(pnc->mlx, pnc->win, pnc->exit_bg, x, y);
	}
	if (c == 'N')
	{
		pnc->enemy->x = x;
		pnc->enemy->y = y;
		mlx_put_image_to_window(pnc->mlx, pnc->win, pnc->enemy->enemy_right, x, y);
	}
}

void	put_score(t_window *pnc)
{
	char	*score;

	score = ft_itoa(pnc->chr->point);
	mlx_string_put(pnc->mlx, pnc->win, 20, 20, 0xFFFFFFFF, score);
	free(score);
}

void	render_map(t_window *pnc)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (pnc->map->mappin[i])
	{
		x = 0;
		j = 0;
		while (pnc->map->mappin[i][j])
		{
			put_img(pnc->map->mappin[i][j++], pnc, x, y);
			put_score(pnc);
			x += PIXEL;
		}
		i++;
		y += PIXEL;
	}
}
