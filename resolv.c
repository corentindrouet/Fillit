/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 09:25:00 by cdrouet           #+#    #+#             */
/*   Updated: 2015/12/08 08:28:09 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	f_init(int (**f)(t_tetri*, char**, int*, int))
{
	f[0] = &i_place;
	f[1] = &o_place;
	f[2] = &t_place;
	f[3] = &l_place;
	f[4] = &j_place;
	f[5] = &z_place;
	f[6] = &s_place;
}

char	**resolv(t_tetri *lst)
{
	char	**ca;
	int		i;
	int		j;
	int		continu;
	int		(*f[7])(t_tetri*, char **, int*, int);

	f_init(f);
	i = tab_size((int)lstlen(lst));
	continu = 0;
	while (continu <= 0 && i <= 11)
	{
		if ((ca = ft_tabnew(i, i + 1)) == NULL)
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
		int (*f[2])(t_tetri *lst, char **carre, int *i, int j), int i)
{
	TABJ();
	PTR();
	if (verifend(lst, ca, i))
		return (verifend(lst, ca, i));
	while (++j[0] < i)
	{
		j[1] = -1;
		while (++j[1] < i)
			if (ca[j[0]][j[1]] == '.')
			{
				j[2] = -1;
				while (++j[2] < 7)
					if (lst->c == ptr[j[2]])
						if (f[j[2]](lst, ca, j, i))
						{
							if ((j[3] = resolv_recur(lst->next, ca, f, i)) > 0)
								return (1);
							else if (j[3] == 0)
								init_place(lst->alpha, i, ca);
							else
								return (-1);
						}
			}
	}
	return (0);
}

int		verifend(t_tetri *lst, char **ca, int i)
{
	if (lst == NULL)
		return (1);
	if (!verif_full(ca, i))
		return (-1);
	return (0);
}

int		tab_size(int ttris)
{
	int i;

	i = 2;
	while ((i * i) < (ttris * 4))
		i++;
	return (i);
}
