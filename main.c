/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 13:09:10 by cdrouet           #+#    #+#             */
/*   Updated: 2015/12/05 15:29:23 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	t_tetri	*ptr;
	char	**ca;
	int		i;

	fd = 0;
	if (argc == 2)
	{
		ptr = creat_lst(argv[1]);
		if (ptr != NULL)
		{
			putlst(ptr);
			ca = resolv(ptr);
			i = -1;
			ft_putendl("----------");
			while (ca[++i])
				ft_putendl(ca[i]);
			ft_putstr("----------");
			del_lst(&ptr);
		}
		else
			ft_putendl("error");
	}
	return (0);
}
