/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 13:09:10 by cdrouet           #+#    #+#             */
/*   Updated: 2015/12/04 16:18:56 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	t_tetri	*ptr;

	fd = 0;
	if (argc == 2)
	{
		ptr = creat_lst(argv[1]);
		if (ptr != NULL)
		{
			putlst(ptr);
			
			del_lst(&ptr);
		}
		else
			ft_putendl("error");
	}
	return (0);
}
