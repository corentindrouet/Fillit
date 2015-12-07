/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_place.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 09:20:45 by aleblanc          #+#    #+#             */
/*   Updated: 2015/12/07 11:22:55 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		j_place_rot1(t_tetri *lst, char **carre, int *i, int j)
{
	if (j < 3)
		return (0);
	if (lst->rot == 0)
		if (i[1] > 0 && (j - (i[0] + 2)) > 0)
			if (carre[i[0]][i[1]] == '.' && carre[i[0] + 1][i[1]] == '.'
				&& carre[i[0] + 2][i[1]] == '.' && carre[i[0] + 2][i[1] - 1] == '.')
			{
				carre[i[0]][i[1]] = lst->alpha;
				carre[i[0] + 1][i[1]] = lst->alpha;
				carre[i[0] + 2][i[1]] = lst->alpha;
				carre[i[0] + 2][i[1] - 1] = lst->alpha;
				return (1);
			}
	if (lst->rot == 1)
		if ((j - (i[0] + 1)) > 0 && (j - (i[1] + 2)) > 0)
			if (carre[i[0]][i[1]] == '.' && carre[i[0] + 1][i[1]] == '.'
				&& carre[i[0] + 1][i[1] + 1] == '.' && carre[i[0] + 1][i[1] + 2] == '.')
			{
				carre[i[0]][i[1]] = lst->alpha;
				carre[i[0] + 1][i[1]] = lst->alpha;
				carre[i[0] + 1][i[1] + 1] = lst->alpha;
				carre[i[0] + 1][i[1] + 2] = lst->alpha;
				return (1);
			}
	return (0);
}


int		j_place_rot2(t_tetri *lst, char **carre, int *i, int j)
{
	if (j < 3)
		return (0);
	if (lst->rot == 2)
		if ((j - (i[1] + 1)) > 0 && (j - (i[0] + 2)) > 0)
			if (carre[i[0]][i[1]] == '.' && carre[i[0]][i[1] + 1] == '.'
				&& carre[i[0] + 1][i[1]] == '.' && carre[i[0] + 2][i[1]] == '.')
			{

				carre[i[0]][i[1]] = lst->alpha;
				carre[i[0]][i[1] + 1] = lst->alpha;
				carre[i[0] + 1][i[1]] = lst->alpha;
				carre[i[0] + 2][i[1]] = lst->alpha;
				return (1);
			}
	if (lst->rot == 3)
		if ((j - (i[0] + 1)) > 0 && (j - (i[1] + 2)) > 0)
			if (carre[i[0]][i[1]] == '.' && carre[i[0]][i[1] + 1] == '.'
				&& carre[i[0]][i[1] + 2] == '.' && carre[i[0] + 1][i[1] + 2] == '.')
			{
				carre[i[0]][i[1]] = lst->alpha;
				carre[i[0]][i[1] + 1] = lst->alpha;
				carre[i[0]][i[1] + 2] = lst->alpha;
				carre[i[0] + 1][i[1] + 2] = lst->alpha;
				return (1);
			}
	return (0);
}

int		j_place(t_tetri *lst, char **carre, int *i, int j)
{
	if (lst->rot < 2)
		return (j_place_rot1(lst, carre, i, j));
	else
		return (j_place_rot2(lst, carre, i, j));
}
