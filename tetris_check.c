/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 09:10:04 by aleblanc          #+#    #+#             */
/*   Updated: 2015/12/04 16:41:54 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

int		check_len_char(char *buf)
{
	int len;
	int	point;
	int	hash;

	len = 0;
	point = 0;
	hash = 0;
	while (*buf == '.' || *buf == '#' || *buf == '\n')
	{
		if ((len == 4 || len == 9 || len == 14) && *buf != '\n')
			return (0);
		if (*buf == '.')
			point++;
		if (*buf == '#')
			hash++;
		len++;
		buf++;
	}
	if ((len == 20 || len == 21) && point == 12 && hash == 4)
		return (1);
	return (0);
}

int		tetris_check(char *str)
{
	char	buf[21];
	int		fd;
	int		ret;
	int		ttris[2];
	int		rettmp;

	ttris[0] = 0;
	ttris[1] = 0;
	if ((fd = open(str, O_RDONLY)) < 0)
		return (0);
	while ((ret = read(fd, buf, 21)) > 0)
	{
		if (check_len_char(buf) == 1)
			ttris[1]++;
		ttris[0]++;
		rettmp = ret;
	}
	close(fd);
	if (ttris[0] == ttris[1] && ttris[1] != 0 && ttris[0] < 27 && rettmp == 20)
		return (1);
	return (0);
}
