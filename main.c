/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 13:09:10 by cdrouet           #+#    #+#             */
/*   Updated: 2015/12/07 13:15:30 by cdrouet          ###   ########.fr       */
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
		if (!tetris_check(argv[1]))
		{
			ft_putendl("error");
			return (0);
		}
		ptr = creat_lst(argv[1]);
		if (ptr != NULL)
		{
			ca = resolv(ptr);
			i = -1;
			while (++i < (int)ft_strlen(ca[0]))
				ft_putendl(ca[i]);
			del_lst(&ptr);
		}
		else
			ft_putendl("error");
	}
	return (0);
}
