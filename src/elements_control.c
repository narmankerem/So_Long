/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knarman <knarman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 05:12:53 by knarman           #+#    #+#             */
/*   Updated: 2024/03/22 09:33:52 by knarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	member_control(t_window *pnc)
{
	int	i;
	int	j;

	i = -1;
	while (pnc->map->mappin[++i])
	{
		j = -1;
		while (pnc->map->mappin[i][++j])
		{
			if (pnc->map->mappin[i][j] != '0' && pnc->map->mappin[i][j] != '1'
				&& pnc->map->mappin[i][j] != 'P'
				&& pnc->map->mappin[i][j] != 'C'
				&& pnc->map->mappin[i][j] != 'E'
				&& pnc->map->mappin[i][j] != 'N')
			{
				ft_putstr_fd("Error: Undefined Char\n", 2);
				close_game(pnc);
			}
		}
	}
}
void	coin_control(t_window *pnc)
{
	int	i;
	int	j;

	i = -1;
	while (pnc->map->mappin[++i])
	{
		j = -1;
		while (pnc->map->mappin[i][++j])
		{
			if (pnc->map->mappin[i][j] == 'C')
				pnc->map->coin_cnt += 1;
		}
	}
	if (pnc->map->coin_cnt <= 0)
	{
		ft_putstr_fd("Not Found Coin in Map\n", 2);
		close_game(pnc);
	}
}
void	player_control(t_window *pnc)
{
	int	i;
	int	j;

	i = 0;
	while (pnc->map->mappin[i])
	{
		j = 0;
		while (pnc->map->mappin[i][j])
		{
			if (pnc->map->mappin[i][j] == 'P')
			{
				pnc->map->p_cnt += 1;
				pnc->chr->x = j;
				pnc->chr->y = i;
			}
			j++;
		}
		i++;
	}
	if (pnc->map->p_cnt != 1)
	{
		ft_putstr_fd("Error: It should be one player in game\n", 2);
		close_game(pnc);
	}
}

void	enemy_control(t_window *pnc)
{
	int	i;
	int	j;

	i = 0;
	while (pnc->map->mappin[i])
	{
		j = 0;
		while (pnc->map->mappin[i][j])
		{
			if (pnc->map->mappin[i][j] == 'N')
			{
				pnc->map->enemy_cnt += 1;
				pnc->enemy->x = j;
				pnc->enemy->y = i;
			}
			j++;
		}
		i++;
	}
	if (pnc->map->enemy_cnt != 1)
	{
		ft_putstr_fd("Error: It should be one enemy in game\n", 2);
		close_game(pnc);
	}
}
void	wall_control(t_window *pnc)
{
	int	i;
	int	last;

	i = -1;
	while (pnc->map->mappin[0][++i])
	{
		if (pnc->map->mappin[0][i] != '1' || pnc->map->mappin[pnc->map->h
			- 1][i] != '1')
		{
			ft_putstr_fd("Error: Wall\n", 2);
			close_game(pnc);
		}
	}
	i = -1;
	last = pnc->map->w - 1;
	while (pnc->map->mappin[++i])
	{
		if (pnc->map->mappin[i][0] != '1' || pnc->map->mappin[i][last] != '1')
		{
			ft_putstr_fd("Error: Wall\n", 2);
			close_game(pnc);
		}
	}
}

void	exit_control(t_window *pnc)
{
	int	i;
	int	j;

	i = -1;
	while (pnc->map->mappin[++i])
	{
		j = -1;
		while (pnc->map->mappin[i][++j])
		{
			if (pnc->map->mappin[i][j] == 'E')
			{
				pnc->map->exit_count += 1;
			}
		}
	}
	if (pnc->map->exit_count < 1)
	{
		ft_putstr_fd("Error: No exit\n", 2);
		close_game(pnc);
	}
	if (pnc->map->exit_count > 1)
	{
		ft_putstr_fd("Error: More than one exit\n", 2);
		close_game(pnc);
	}
}
