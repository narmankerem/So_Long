/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knarman <knarman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:40:56 by knarman          #+#    #+#             */
/*   Updated: 2024/03/22 00:55:08 by knarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>

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

static void	game_init_control(t_window *pnc, char *path)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	pnc->chr = ft_calloc(1, sizeof(t_char));
	pnc->enemy = ft_calloc(1, sizeof(t_enemy));
	if (!pnc->chr || !pnc->enemy)
	{
		ft_putstr_fd("ERROR: Player Struct or Enemy struct Calloc Error:", 2);
		exit(-1);
	}
	read_map(pnc, path);
	map_size_control(pnc);
	member_control(pnc);
	player_control(pnc);
	enemy_control(pnc);
	wall_control(pnc);
	exit_control(pnc);
	coin_control(pnc);
	path_finder_control(pnc);
	render_img(pnc, x, y);
}

int	close_game(t_window *pnc)
{
	int	i;

	i = 0;
	while (pnc->map->mappin[i])
		free(pnc->map->mappin[++i]);
	i = 0;
	while (pnc->map->clone_map[i])
		free(pnc->map->clone_map[++i]);
	free(pnc->map->mappin);
	free(pnc->map->clone_map);
	free(pnc->map);
	free(pnc->enemy);
	free(pnc->chr);
	exit(-1);
	return (0);
}
int	close_game_mlx(t_window *pnc)
{
	mlx_destroy_image(pnc->mlx, pnc->chr->chr_front);
	mlx_destroy_image(pnc->mlx, pnc->chr->chr_back);
	mlx_destroy_image(pnc->mlx, pnc->chr->chr_right);
	mlx_destroy_image(pnc->mlx, pnc->chr->chr_left);
	mlx_destroy_image(pnc->mlx, pnc->enemy->enemy_right);
	mlx_destroy_image(pnc->mlx, pnc->coin_bg);
	mlx_destroy_image(pnc->mlx, pnc->exit_bg);
	mlx_destroy_image(pnc->mlx, pnc->wall_bg);
	mlx_destroy_image(pnc->mlx, pnc->img_bg);
	mlx_destroy_window(pnc->mlx, pnc->win);
	exit(-1);
	return (0);
}


int	main(int ac, char **av)
{
	t_window	*so_long;

	so_long = ft_calloc(1, sizeof(t_window));
	if (!so_long)
		return (ft_putstr_fd("calloc 1", 2), -1);
	if (ac == 2)
	{
		file_name_check(av[1]);
		xpm_control();
		xpm_control_2();
		game_init_control(so_long, av[1]);
		render_map(so_long);
		mlx_hook(so_long->win, 2, 0, walk, so_long);
		mlx_hook(so_long->win, 17, 0, close_game, so_long);
		mlx_loop_hook(so_long->mlx, enemymove, so_long);
		mlx_loop(so_long->mlx);
	}
	else
	{
		ft_putstr_fd("Error: None Argument\n", 2);
		return (-1);
	}
}
