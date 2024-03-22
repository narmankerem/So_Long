/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knarman <knarman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 04:27:46 by knarman          #+#    #+#             */
/*   Updated: 2024/03/21 23:26:09 by knarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_size_control(t_window *pnc)
{
	int		i;
	size_t	len;

	i = 0;
	len = pnc->map->w;
	while (pnc->map->mappin[i])
	{
		if (ft_strlen(pnc->map->mappin[i]) != len)
		{
			ft_putstr_fd("Error: Map size\n", 2);
			close_game(pnc);
		}
		i++;
	}
}
