/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 13:09:10 by cdrouet           #+#    #+#             */
/*   Updated: 2015/12/08 09:20:14 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	buf;
	int		fd;

	if (argc == 2)
	{
		if (!run(argv[1]))
			ft_putendl("error");
	}
	else if (argc == 1)
	{
		fd = open("tempo.txt",
			O_CREAT | O_TRUNC | O_RDWR | O_APPEND,
				S_IRUSR | S_IWUSR | S_IXUSR);
		while (read(0, &buf, 1))
			write(fd, &buf, 1);
		if (!run("tempo.txt"))
			ft_putendl("error");
	}
	return (0);
}

void	ft_puttab(char **ca)
{
	int		i;
	int		len;

	i = -1;
	len = (int)ft_strlen(ca[0]);
	while (++i < len)
		ft_putendl(ca[i]);
}

int		run(char *arg)
{
	t_tetri	*ptr;
	char	**ca;

	if (!tetris_check(arg))
		return (0);
	if ((ptr = creat_lst(arg)) == NULL)
		return (0);
	if ((ca = resolv(ptr)) == NULL)
		return (0);
	ft_puttab(ca);
	del_lst(&ptr);
	return (1);
}
