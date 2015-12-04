/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 09:35:37 by cdrouet           #+#    #+#             */
/*   Updated: 2015/12/04 15:18:02 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	i_search(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '#')
		i++;
	if (i == 0 || i == 5 || i == 10 || i == 15)
	{
		if (buf[i + 1] == '#' && buf[i + 2] == '#' && buf[i + 3] == '#')
			return (1);
		else if (i != 0)
			return (-1);
	}
	if (i == 0 || i == 1 || i == 2 || i == 3)
	{
		if (buf[i + 5] == '#' && buf[i + 10] == '#' && buf[i + 15] == '#')
			return (0);
		else
			return (-1);
	}
	return (-1);
}

int	o_search(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '#')
		i++;
	if (i < 13)
		if (buf[i + 1] == '#' && buf[i + 5] == '#' && buf[i + 6] == '#')
			return (1);
	return (-1);
}

int	t_search(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '#')
		i++;
	if (i < 8)
		if (buf[i + 5] == '#' && buf[i + 6] == '#' && buf[i + 10] == '#')
			return (3);
	if (i < 9)
		if (buf[i + 4] == '#' && buf[i + 5] == '#' && buf[i + 10] == '#')
			return (1);
	if (i < 12)
		if (buf[i + 1] == '#' && buf[i + 2] == '#' && buf[i + 6] == '#')
			return (0);
	if (i < 13)
		if (buf[i + 4] == '#' && buf[i + 5] == '#' && buf[i + 6] == '#')
			return (2);
	return (-1);
}

int	l_search(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '#')
		i++;
	if (i < 8)
	{
		if (buf[i + 5] == '#' && buf[i + 10] == '#' && buf[i + 11] == '#')
			return (0);
		else if (buf[i + 1] == '#' && buf[i + 6] == '#' && buf[i + 11] == '#')
			return (2);
	}
	if (i < 12)
		if (buf[i + 1] == '#' && buf[i + 2] == '#' && buf[i + 5] == '#')
			return (1);
	if (i < 14)
		if (buf[i + 3] == '#' && buf[i + 4] == '#' && buf[i + 5] == '#')
			return (3);
	return (-1);
}
