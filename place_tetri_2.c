/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_tetri_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 09:00:45 by cdrouet           #+#    #+#             */
/*   Updated: 2015/12/07 13:43:05 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		z_place(t_tetri *lst, char **carre, int *i, int j)
{
	if (lst->rot == 0)
		if ((j - (i[0] + 1)) > 0 && (j - (i[1] + 2)) > 0)
			if (carre[i[0]][i[1]] == '.' && carre[i[0]][i[1] + 1] == '.'
				&& carre[i[0] + 1][i[1] + 1] == '.'
					&& carre[i[0] + 1][i[1] + 2] == '.')
			{
				carre[i[0]][i[1]] = lst->alpha;
				carre[i[0]][i[1] + 1] = lst->alpha;
				carre[i[0] + 1][i[1] + 1] = lst->alpha;
				carre[i[0] + 1][i[1] + 2] = lst->alpha;
				return (1);
			}
	if (lst->rot == 1)
		if ((j - (i[0] + 2)) > 0 && i[1] > 0)
			if (carre[i[0]][i[1]] == '.' && carre[i[0] + 1][i[1]] == '.'
				&& carre[i[0] + 1][i[1] - 1] == '.'
					&& carre[i[0] + 2][i[1] - 1] == '.')
			{
				carre[i[0]][i[1]] = lst->alpha;
				carre[i[0] + 1][i[1]] = lst->alpha;
				carre[i[0] + 1][i[1] - 1] = lst->alpha;
				carre[i[0] + 2][i[1] - 1] = lst->alpha;
				return (1);
			}
	return (0);
}

int		s_place(t_tetri *lst, char **carre, int *i, int j)
{
	if (lst->rot == 0)
		if ((j - (i[0] + 1)) > 0 && (j - (i[1] + 1)) > 0 && i[1] > 0)
			if (carre[i[0]][i[1]] == '.' && carre[i[0]][i[1] + 1] == '.'
				&& carre[i[0] + 1][i[1]] == '.'
					&& carre[i[0] + 1][i[1] - 1] == '.')
			{
				carre[i[0]][i[1]] = lst->alpha;
				carre[i[0]][i[1] + 1] = lst->alpha;
				carre[i[0] + 1][i[1]] = lst->alpha;
				carre[i[0] + 1][i[1] - 1] = lst->alpha;
				return (1);
			}
	if (lst->rot == 1)
		if ((j - (i[0] + 2)) > 0 && (j - (i[1] + 1)) > 0)
			if (carre[i[0]][i[1]] == '.' && carre[i[0] + 1][i[1]] == '.'
				&& carre[i[0] + 1][i[1] + 1] == '.'
					&& carre[i[0] + 2][i[1] + 1] == '.')
			{
				carre[i[0]][i[1]] = lst->alpha;
				carre[i[0] + 1][i[1]] = lst->alpha;
				carre[i[0] + 1][i[1] + 1] = lst->alpha;
				carre[i[0] + 2][i[1] + 1] = lst->alpha;
				return (1);
			}
	return (0);
}

int		t_place(t_tetri *lst, char **carre, int *i, int j)
{
	if (lst->rot <= 1)
		return (t_place_1(lst, carre, i, j));
	else
		return (t_place_2(lst, carre, i, j));
}

int		t_place_1(t_tetri *lst, char **carre, int *i, int j)
{
	if (lst->rot == 0)
		if ((j - (i[0] + 1)) > 0 && (j - (i[1] + 2)))
			if (carre[i[0]][i[1]] == '.' && carre[i[0]][i[1] + 1] == '.'
				&& carre[i[0]][i[1] + 2] == '.'
					&& carre[i[0] + 1][i[1] + 1] == '.')
			{
				carre[i[0]][i[1]] = lst->alpha;
				carre[i[0]][i[1] + 1] = lst->alpha;
				carre[i[0]][i[1] + 2] = lst->alpha;
				carre[i[0] + 1][i[1] + 1] = lst->alpha;
				return (1);
			}
	if (lst->rot == 1)
		if ((j - (i[0] + 2)) > 0 && i[1] > 0)
			if (carre[i[0]][i[1]] == '.' && carre[i[0] + 1][i[1]] == '.'
				&& carre[i[0] + 1][i[1] - 1] == '.'
					&& carre[i[0] + 2][i[1]] == '.')
			{
				carre[i[0]][i[1]] = lst->alpha;
				carre[i[0] + 1][i[1]] = lst->alpha;
				carre[i[0] + 1][i[1] - 1] = lst->alpha;
				carre[i[0] + 2][i[1]] = lst->alpha;
				return (1);
			}
	return (0);
}

int		t_place_2(t_tetri *lst, char **carre, int *i, int j)
{
	if (lst->rot == 2)
		if ((j - (i[0] + 1)) > 0 && (j - (i[1] + 1)) && i[1] > 0)
			if (carre[i[0]][i[1]] == '.' && carre[i[0] + 1][i[1]] == '.'
				&& carre[i[0] + 1][i[1] - 1] == '.'
					&& carre[i[0] + 1][i[1] + 1] == '.')
			{
				carre[i[0]][i[1]] = lst->alpha;
				carre[i[0] + 1][i[1]] = lst->alpha;
				carre[i[0] + 1][i[1] - 1] = lst->alpha;
				carre[i[0] + 1][i[1] + 1] = lst->alpha;
				return (1);
			}
	if (lst->rot == 3)
		if ((j - (i[0] + 2)) > 0 && (j - (i[1] + 1)) > 0)
			if (carre[i[0]][i[1]] == '.' && carre[i[0] + 1][i[1]] == '.'
				&& carre[i[0] + 1][i[1] + 1] == '.'
					&& carre[i[0] + 2][i[1]] == '.')
			{
				carre[i[0]][i[1]] = lst->alpha;
				carre[i[0] + 1][i[1]] = lst->alpha;
				carre[i[0] + 1][i[1] + 1] = lst->alpha;
				carre[i[0] + 2][i[1]] = lst->alpha;
				return (1);
			}
	return (0);
}
