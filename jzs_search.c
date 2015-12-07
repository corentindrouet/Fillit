/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jzs_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 13:00:35 by cdrouet           #+#    #+#             */
/*   Updated: 2015/12/07 11:46:10 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	j_search(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '#')
		i++;
	if (i < 8)
		if (buf[i + 1] == '#' && buf[i + 5] == '#' && buf[i + 10] == '#')
			return (2);
	if (i < 9)
		if (buf[i + 5] == '#' && buf[i + 9] == '#' && buf[i + 10] == '#')
			return (0);
	if (i < 12)
	{
		if (buf[i + 5] == '#' && buf[i + 6] == '#' && buf[i + 7] == '#')
			return (1);
		if (buf[i + 1] == '#' && buf[i + 2] == '#' && buf[i + 7] == '#')
			return (3);
	}
	return (-1);
}

int	z_search(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '#')
		i++;
	if (i < 9)
		if (buf[i + 4] == '#' && buf[i + 5] == '#' && buf[i + 9] == '#')
			return (1);
	if (i < 12)
		if (buf[i + 1] == '#' && buf[i + 6] == '#' && buf[i + 7] == '#')
			return (0);
	return (-1);
}

int	s_search(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '#')
		i++;
	if (i < 8)
		if (buf[i + 5] == '#' && buf[i + 6] == '#' && buf[i + 11] == '#')
			return (1);
	if (i < 13)
		if (buf[i + 1] == '#' && buf[i + 4] == '#' && buf[i + 5] == '#')
			return (0);
	return (-1);
}
