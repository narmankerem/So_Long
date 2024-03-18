/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knarman <knarman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:40:56 by knarman          #+#    #+#             */
/*   Updated: 2024/03/18 07:54:29 by knarman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>

void	game_map_control(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Map file path");
		exit(-1);
	}
	close(fd);
}

void	file_name_check(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (!str)
	{
		perror("File name check");
		exit(-1);
	}
	if (str[i - 1] != 'r' && str[i - 2] != 'e' && str[i - 3] != 'b' && str[i
		- 4] != 'e')
	{
		perror("File name check");
		exit(-1);
	}
}

void	game_init_control(t_window *pnc, char *path)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	read_map(pnc, path);
	map_size_control(pnc);
	char_control(pnc);
	player_control(pnc);
	wall_control(pnc);
	exit_control(pnc);
	coin_control(pnc);
	get_img()
}

void	close_game(t_window *pnc, int flag)
{
	int	i;

	i = 0;
	if (flag == 0)
	{
		while (pnc->map->mappin[i])
			free(pnc->map->mappin[i]);
		free(pnc->map->mappin);
		free(pnc->map);
		exit(-1);
	}
}

int	main(int ac, char **av)
{
	t_window	so_long;

	if (ac == 2)
	{
		file_name_check(av[1]);
		xpm_control();
		xpm_control2();
		game_map_control(av[1]);
		game_init_control(&so_long, av[1]);
	}
	else
	{
		ft_putstr_fd("Error: None Argument\n", 2);
		return (-1);
	}
}
