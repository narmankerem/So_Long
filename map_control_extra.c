/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control_extra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knarman <knarman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:40:07 by knarman            #+#    #+#             */
/*   Updated: 2024/03/18 15:40:07 by knarman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_size_control(t_window *pnc)
{
	int	i;
	int	len;

	i = 0;
	len = pnc->map->w;
	while (pnc->map->mappin[i])
	{
		if (ft_strlen(pnc->map->mappin[i]) != len)
		{
			ft_putstr_fd("Error: Map size\n", 2);
			close_game(pnc, 0);
		}
		i++;
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
				pnc->map->p_cnt += 1;
			j++;
		}
		i++;
	}
	if (pnc->map->p_cnt == 0)
	{
		ft_putstr_fd("Error: No pleyer has been spawned\n", 2);
		close_game(pnc, 0);
	}
	if (pnc->map->p_cnt > 1)
	{
		ft_putstr_fd("Error: More than one player has been spawned\n", 2);
		close_game(pnc, 0);
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
			close_game(pnc, 0);
		}
	}
	i = -1;
	last = pnc->map->w - 1;
	while (pnc->map->mappin[++i])
	{
		if (pnc->map->mappin[i][0] != '1' || pnc->map->mappin[i][last] != '1')
		{
			ft_putstr_fd("Error: Wall\n", 2);
			close_game(pnc, 0);
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
		close_game(pnc, 0);
	}
	if (pnc->map->exit_count > 1)
	{
		ft_putstr_fd("Error: More than one exit\n", 2);
		close_game(pnc, 0);
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
		close_game(pnc, 0);
	}
}
