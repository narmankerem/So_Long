/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knarman <knarman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:43:15 by knarman          #+#    #+#             */
/*   Updated: 2024/03/18 07:27:55 by knarman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>

typedef struct s_map
{
	char	**mappin;
	int		w;
	int		h;
	int		cb;
	int		gate_x;
	int		gate_y;
	int		p_cnt;
	int		exit_count;
	int		coin_cnt;
}			t_map;

typedef struct s_window
{
	t_map	*map;
	void	*win;
	void	*mlx;
	void	*img_bg;
	void	*block_bg;
	void	*c_bg;
	void	*end_bg;
	int		height;
	int		width;
}			t_window;

void		ft_putstr_fd(char *s, int fd);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_strlen(const char *str);
void		*ft_calloc(size_t count, size_t size);

#endif