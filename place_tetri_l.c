/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_tetri_l.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 09:43:55 by cdrouet           #+#    #+#             */
/*   Updated: 2015/12/07 11:27:09 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		l_place(t_tetri *lst, char **carre, int *i, int j)
{
	if (lst->rot <= 1)
		return (l_place_1(lst, carre, i, j));
	else
		return (l_place_2(lst, carre, i, j));
}

int		l_place_1(t_tetri *lst, char **carre, int *i, int j)
{
	if (lst->rot == 0)
		if ((j - (i[0] + 2)) > 0 && (j - (i[1] + 1)))
			if (carre[i[0]][i[1]] == '.' && carre[i[0] + 1][i[1]] == '.'
				&& carre[i[0] + 2][i[1]] == '.'
					&& carre[i[0] + 2][i[1] + 1] == '.')
			{
				carre[i[0]][i[1]] = lst->alpha;
				carre[i[0] + 1][i[1]] = lst->alpha;
				carre[i[0] + 2][i[1]] = lst->alpha;
				carre[i[0] + 2][i[1] + 1] = lst->alpha;
				return (1);
			}
	if (lst->rot == 1)
		if ((j - (i[0] + 1)) > 0 && (j - (i[1] + 2)) > 0)
			if (carre[i[0]][i[1]] == '.' && carre[i[0] + 1][i[1]] == '.'
				&& carre[i[0]][i[1] + 1] == '.'
					&& carre[i[0]][i[1] + 2] == '.')
			{
				carre[i[0]][i[1]] = lst->alpha;
				carre[i[0] + 1][i[1]] = lst->alpha;
				carre[i[0]][i[1] + 1] = lst->alpha;
				carre[i[0]][i[1] + 2] = lst->alpha;
				return (1);
			}
	return (0);
}

int		l_place_2(t_tetri *lst, char **carre, int *i, int j)
{
	if (lst->rot == 2)
		if ((j - (i[0] + 2)) > 0 && (j - (i[1] + 1)))
			if (carre[i[0]][i[1]] == '.' && carre[i[0]][i[1] + 1] == '.'
				&& carre[i[0] + 1][i[1] + 1] == '.'
					&& carre[i[0] + 2][i[1] + 1] == '.')
			{
				carre[i[0]][i[1]] = lst->alpha;
				carre[i[0]][i[1] + 1] = lst->alpha;
				carre[i[0] + 1][i[1] + 1] = lst->alpha;
				carre[i[0] + 2][i[1] + 1] = lst->alpha;
				return (1);
			}
	if (lst->rot == 3)
		if ((j - (i[0] + 1)) > 0 && i[1] > 1)
			if (carre[i[0]][i[1]] == '.' && carre[i[0] + 1][i[1]] == '.'
				&& carre[i[0] + 1][i[1] - 1] == '.'
					&& carre[i[0] + 1][i[1] - 2] == '.')
			{
				carre[i[0]][i[1]] = lst->alpha;
				carre[i[0] + 1][i[1]] = lst->alpha;
				carre[i[0] + 1][i[1] - 1] = lst->alpha;
				carre[i[0] + 1][i[1] - 2] = lst->alpha;
				return (1);
			}
	return (0);
}
