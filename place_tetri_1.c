/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_tetri_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 10:23:21 by cdrouet           #+#    #+#             */
/*   Updated: 2015/12/07 13:43:07 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		i_place(t_tetri *lst, char **carre, int *i, int j)
{
	int	l;

	l = -1;
	if (j < 4)
		return (0);
	if (lst->rot == 0)
		if ((j - (i[0] + 3)) > 0)
			if (carre[i[0]][i[1]] == '.' && carre[i[0] + 1][i[1]] == '.'
				&& carre[i[0] + 2][i[1]] == '.' && carre[i[0] + 3][i[1]] == '.')
			{
				while (++l < 4)
					carre[i[0] + l][i[1]] = lst->alpha;
				return (1);
			}
	l = -1;
	if (lst->rot == 1)
		if ((j - (i[1] + 3)) > 0)
			if (carre[i[0]][i[1]] == '.' && carre[i[0]][i[1] + 1] == '.'
				&& carre[i[0]][i[1] + 2] == '.' && carre[i[0]][i[1] + 3] == '.')
			{
				while (++l < 4)
					carre[i[0]][i[1] + l] = lst->alpha;
				return (1);
			}
	return (0);
}

int		o_place(t_tetri *lst, char **carre, int *i, int j)
{
	if ((j - (i[0] + 1) > 0) && (j - (i[1] + 1) > 0))
	{
		if (carre[i[0]][i[1]] == '.' && carre[i[0]][i[1] + 1] == '.'
			&& carre[i[0] + 1][i[1]] == '.' && carre[i[0] + 1][i[1] + 1] == '.')
		{
			carre[i[0]][i[1]] = lst->alpha;
			carre[i[0] + 1][i[1]] = lst->alpha;
			carre[i[0]][i[1] + 1] = lst->alpha;
			carre[i[0] + 1][i[1] + 1] = lst->alpha;
			return (1);
		}
	}
	return (0);
}

void	init_place(char c, int i, char **ca)
{
	int	j[2];

	j[0] = -1;
	while (++j[0] < i)
	{
		j[1] = -1;
		while (++j[1] < i)
			if (ca[j[0]][j[1]] == c)
				ca[j[0]][j[1]] = '.';
	}
}

int		verif_full(char **ca, int i)
{
	int	j[2];
	int	nb;

	j[0] = -1;
	nb = 0;
	while (++j[0] < i)
	{
		j[1] = -1;
		while (++j[1] < i)
			if (ca[j[0]][j[1]] == '.')
				nb++;
	}
	if (nb <= 3)
		return (0);
	return (1);
}
