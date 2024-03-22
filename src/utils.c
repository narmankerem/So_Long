/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knarman <knarman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:43:20 by knarman          #+#    #+#             */
/*   Updated: 2024/03/22 00:44:44 by knarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

void	ft_putnbr(int number)
{
	if (number > 9)
		ft_putnbr(number / 10);
	write(1, &"0123456789"[number % 10], 1);
}
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	i;

	i = -1;
	p = malloc(count * size);
	if (!p)
		return (NULL);
	while (++i, i < count * size)
		((char *)p)[i] = 0;
	return (p);
}

static int	ft_numlen(int num)
{
	int	i;

	if (num == 0)
		return (1);
	i = 0;
	while (num > 0 || num < 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*ptr;
	long	nbr;

	nbr = n;
	len = ft_numlen(nbr);
	if (n < 0)
	{
		nbr = -nbr;
		len++;
	}
	ptr = (char *)malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	while (nbr > 0)
	{
		ptr[--len] = nbr % 10 + 48;
		nbr /= 10;
	}
	if (n < 0)
		ptr[0] = '-';
	if (n == 0)
		ptr[0] = '0';
	return (ptr);
}


