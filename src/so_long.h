/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knarman <knarman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:43:15 by knarman          #+#    #+#             */
/*   Updated: 2024/03/22 00:50:03 by knarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#define SO_LONG_H
#define PIXEL 64

#include "../minilibx/mlx.h"
#include "get_next_line/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_map
{
	char	**mappin;
	char	**clone_map;
	int		w;
	int		h;
	int		cb;
	int		exit_x;
	int		exit_y;
	int		p_cnt;
	int		enemy_cnt;
	int		exit_count;
	int		coin_cnt;
}			t_map;

typedef struct s_char
{
	int		x;
	int		y;
	int		point;
	void	*chr_front;
	void	*chr_back;
	void	*chr_left;
	void	*chr_right;
	void	*chr_current;
}			t_char;

typedef struct s_enemy
{
	int		x;
	int		y;
	void	*enemy_left;
	void	*enemy_right;
	void	*enemy_current;
	void	*chr_left;
	void	*chr_right;
}			t_enemy;

typedef struct s_window
{
	t_map	*map;
	t_char	*chr;
	t_enemy	*enemy;

	int		coin;
	int		exit;
	void	*win;
	void	*mlx;
	void	*img_bg;
	void	*wall_bg;
	void	*coin_bg;
	void	*exit_bg;
	int		height;
	int		width;
}			t_window;

void		ft_putnbr(int number);

void		ft_putstr_fd(char *s, int fd);
void		*ft_calloc(size_t count, size_t size);
void		read_map(t_window *pnc, char *path);
void		map_size_control(t_window *pnc);
void		player_control(t_window *pnc);
void		enemy_control(t_window *pnc);
void		xpm_control(void);
void		wall_control(t_window *pnc);
void		exit_control(t_window *pnc);
void		xpm_control_2(void);
void		coin_control(t_window *pnc);
void		member_control(t_window *pnc);
void		path_finder_control(t_window *pnc);
void		render_img(t_window *pnc, int x, int y);
int			close_game(t_window *pnc);
int			close_game_mlx(t_window *pnc);
void		render_map(t_window *pnc);
char		*ft_itoa(int n);
char		**ft_split(char const *s, char c);
int			walk(int keycode, void *param);

void		*ft_memcpy(void *dst, const void *src, size_t n);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
int			enemymove(t_window *pnc);