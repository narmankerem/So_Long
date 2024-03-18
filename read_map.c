/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knarman <knarman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 03:55:41 by knarman          #+#    #+#             */
/*   Updated: 2024/03/18 07:43:21 by knarman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_checknl(t_map *map, char c)
{
	if (c == '\n')
	{
		ft_putstr_fd("Error: Empty map\n", 2);
		close_game(map, 0);
	}
}

void	coin_count(t_map *map, char *str)
{
	int	i;

	i = -1;
	while (str[++i] == 'C')
		map->cb += 1;
}

void	strappend(t_map *map, char **ptr, char *str)
{
	char	*tmp;

	tmp = *ptr;
	ptr = ft_strjoin(tmp, str);
	if (!ptr)
	{
		if (tmp)
			free(tmp);
		perror("Error: Malloc --strappend--");
		close_game(map, 0);
	}
	if (tmp)
		free(tmp);
}

char	*file_to_read(t_map *map, char *path)
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
		perror("File to read");
		close_game(map, 0);
	}
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		read_checknl(map, str[0]);
		coin_count(map, str);
		strappend(map, &ptr, str);
		free(str);
	}
	return (close(fd), ptr);
}

void	read_map(t_map *map, char *path)
{
	char	*str;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	str = file_to_read(map, path);
	map->mappin = ft_split(str, '\n');
	if (!map->mappin)
	{
		perror("Split");
		free(str);
		close_game(map, 0);
	}
	map->h = 0;
	while (map->mappin[map->h])
		map->h++;
	map->w = ft_strlen(map->mappin[0]);
	free(str);
}
