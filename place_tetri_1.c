/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_tetri_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 10:23:21 by cdrouet           #+#    #+#             */
/*   Updated: 2015/12/05 16:39:09 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		i_place(t_tetri *lst, char **carre, int i, int j)
{
	int	l;

	l = -1;
	if (((int)ft_strlen(carre[0]) - (i + 3)) >= 0)
		if (lst->rot == 0)
			if (carre[i][j] == '.' && carre[i + 1][j] == '.'
				&& carre[i + 2][j] == '.' && carre[i + 3][j] == '.')
			{
				while (++l < 4)
					carre[i + l][j] = lst->alpha;
				return (1);
			}
	if (((int)ft_strlen(carre[0]) - (j + 3)) >= 0)
		if (lst->rot == 1)
			if (carre[i][j] == '.' && carre[i][j + 1] == '.'
				&& carre[i][j + 2] == '.' && carre[i][j + 3] == '.')
			{
				while (++l < 4)
					carre[i][j + l] = lst->alpha;
				return (1);
			}
	return (0);
}

int		o_place(t_tetri *lst, char **carre, int i, int j)
{
	if (((int)ft_strlen(carre[0]) - (i + 1) >= 0)
		&& (int)ft_strlen(carre[0]) - (j + 1) >= 0)
	{
		if (carre[i][j] == '.' && carre[i][j + 1] == '.'
			&& carre[i + 1][j] == '.' && carre[i + 1][j + 1] == '.')
		{
			carre[i][j] = lst->alpha;
			carre[i + 1][j] = lst->alpha;
			carre[i][j + 1] = lst->alpha;
			carre[i + 1][j + 1] = lst->alpha;
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

	j[0] = -1;
	while (++j[0] < i)
	{
		j[1] = -1;
		while (++j[1] < i)
			if (ca[j[0]][j[1]] == '.')
				return (1);
	}
	return (0);
}
