/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 09:25:00 by cdrouet           #+#    #+#             */
/*   Updated: 2015/12/05 16:45:51 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**resolv(t_tetri *lst)
{
	char	**ca;
	int		i;
	int		j;
	int		continu;

	FP();
	i = 4;
	continu = 0;
	while (continu <= 0)
	{
		if ((ca = ft_tabnew(i, i)) == NULL)
			return (NULL);
		ft_inittab(ca, i, i, '.');
		continu = resolv_recur(lst, ca, f, i);
		if (continu <= 0)
		{
			j = -1;
			while (++j < i)
				free(ca[j]);
			free(ca);
		}
		i++;
	}
	return (ca);
}

int		resolv_recur(t_tetri *lst, char **ca, 
		int (*f[2])(t_tetri *lst, char **carre, int i, int j), int i)
{
	int		j[3];
	char	ptr[10] = "iotljzs";

	if (lst == NULL)
		return (1);
	if (!verif_full(ca, i))
		return (-1);
	j[0] = -1;
	while (++j[0] < i)
	{
		j[1] = -1;
		while (++j[1] < i)
		{
			if (ca[j[0]][j[1]] == '.')
			{
				j[2] = -1;
				while (++j[2] < 7)
				{
					if (lst->c == ptr[j[2]])
					{
						if (f[j[2]](lst, ca, j[0], j[1]))
						{
							if ((j[2] = resolv_recur(lst->next, ca, f, i)) > 0)
							{
								return (1);
							}
							else if (j[2] == 0)
								init_place(lst->alpha, i, ca);
							else
								return (-1);
						}
					}
				}
			}
		}
	}
	return (0);
}
