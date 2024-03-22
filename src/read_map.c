/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knarman <knarman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 03:55:41 by knarman          #+#    #+#             */
/*   Updated: 2024/03/22 00:39:32 by knarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <unistd.h>

static void	read_checknl(t_window *pnc, char c)
{
	if (c == '\n')
	{
		ft_putstr_fd("Error: Empty map\n", 2);
		close_game(pnc);
	}
}

static void	ptrappend(t_window *pnc, char **ptr, char *str)
{
	if (!*ptr && str)
	{
		*ptr = ft_strdup(str);
		if (!*ptr)
			free(str);
		return ;
	}
	*ptr = ft_strjoin(*ptr, str);
	if (!ptr)
	{
		free(str);
		perror("Error: Malloc --strappend--");
		close_game(pnc);
	}
}

static char	*file_to_read(t_window *pnc, char *path)
{
	char	*str;
	char	*ptr;
	int		i;
	int		fd;

	ptr = NULL;
	i = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror("Map file path");
		exit(-1);
	}
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		read_checknl(pnc, str[0]);
		ptrappend(pnc, &ptr, str);
		free(str);
	}
	close(fd);
	return (ptr);
}

void	read_map(t_window *pnc, char *path)
{
	char	*str;

	pnc->map = ft_calloc(1, sizeof(t_map));
	if (!pnc->map)
	{
		ft_putstr_fd("Error: Calloc read map", 2);
		exit(-1);
	}
	str = file_to_read(pnc, path);
	pnc->map->mappin = ft_split(str, '\n');
	pnc->map->clone_map = ft_split(str, '\n');
	if (!pnc->map->mappin || !pnc->map->clone_map)
	{
		perror("Split");
		free(str);
		close_game(pnc);
	}
	pnc->map->h = 0;
	while (pnc->map->mappin[pnc->map->h])
		pnc->map->h++;
	pnc->map->w = ft_strlen(pnc->map->mappin[0]);
	free(str);
}
