/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_tetri_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 10:23:21 by cdrouet           #+#    #+#             */
/*   Updated: 2015/12/05 14:48:07 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		i_place(t_tetri *lst, char **carre, int i, int j)
{
	int	l;

	l = -1;
	if (carre[i + 1][j + 1] && carre[i + 2][j + 2] && carre[i + 3][j + 3])
	{
		if (lst->rot == 0)
			if (carre[i][j] == '.' && carre[i + 1][j] == '.'
				&& carre[i + 2][j] == '.' && carre[i + 3][j] == '.')
			{
				while (++l < 4)
					carre[i + l][j] = lst->alpha;
				return (1);
			}
		if (lst->rot == 1)
			if (carre[i][j] == '.' && carre[i][j + 1] == '.'
				&& carre[i][j + 2] == '.' && carre[i][j + 3] == '.')
			{
				while (++l < 4)
					carre[i + l][j] = lst->alpha;
				return (1);
			}
	}
	return (0);
}

int		o_place(t_tetri *lst, char **carre, int i, int j)
{
	if (carre[i + 1][j + 1])
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
