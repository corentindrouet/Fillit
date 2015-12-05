/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_tetriminos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:33:48 by cdrouet           #+#    #+#             */
/*   Updated: 2015/12/05 10:15:24 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri	*creat_elem(char c, int rot)
{
	t_tetri	*ptr;

	if ((ptr = (t_tetri*)malloc(sizeof(t_tetri))) == NULL)
		return (NULL);
	ptr->c = c;
	ptr->rot = rot;
	ptr->next = NULL;
	return (ptr);
}

int		add_elem(t_tetri **lst, t_tetri *new)
{
	t_tetri	*ptr;
	int		i;

	i = 0;
	ptr = *lst;
	if (new == NULL)
		return (0);
	if (ptr == NULL)
	{
		new->alpha = 'A' + i;
		*lst = new;
	}
	else
	{
		i = 1;
		while (ptr->next)
		{
			i++;
			ptr = ptr->next;
		}
		new->alpha = 'A' + i;
		ptr->next = new;
	}
	return (1);
}

void	putlst(t_tetri *lst)
{
	while (lst)
	{
		ft_putchar(lst->c);
		ft_putchar(' ');
		ft_putchar(lst->alpha);
		ft_putchar(' ');
		ft_putnbr(lst->rot);
		ft_putchar('\n');
		lst = lst->next;
	}
}

void	del_lst(t_tetri **lst)
{
	t_tetri	*ptr;

	ptr = *lst;
	if (ptr->next)
		del_lst(&(ptr->next));
	else
		free(ptr);
	ptr = NULL;
}

t_tetri	*creat_lst(char *file)
{
	char	*buf[2];
	int		fd;
	t_tetri	*ptr;
	int		i[2];

	F();
	ptr = NULL;
	if ((fd = open(file, O_RDONLY)) < 0)
		return (NULL);
	if (((buf[0] = ft_strnew(22)) == NULL)
		|| ((buf[1] = ft_strnew(8)) == NULL))
		return (NULL);
	while (read(fd, buf[0], 21))
	{
		i[0] = 0;
		while (i[0] < 7 && (i[1] = f[i[0]](buf[0])) < 0)
			i[0]++;
		buf[1] = "iotljzs";
		if (i[0] == 7)
			return (NULL);
		if (!add_elem(&ptr, creat_elem(buf[1][i[0]], i[1])))
			return (NULL);
	}
	close(fd);
	return (ptr);
}
