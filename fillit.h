/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 13:09:52 by cdrouet           #+#    #+#             */
/*   Updated: 2015/12/08 09:36:16 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"
# define I()	&i_search
# define O()	&o_search
# define T()	&t_search
# define L()	&l_search
# define J()	&j_search
# define Z()	&z_search
# define S()	&s_search
# define F() int	(*f[7])(char*) = {I(), O(), T(), L(), J(), Z(), S()};
# define TABJ()	int	j[4] = {-1, -1, -1, 0}
# define PTR()	char	*ptr = "iotljzs"

typedef struct		s_tetri
{
	char			c;
	char			alpha;
	int				rot;
	struct s_tetri	*next;
}					t_tetri;

int					tab_size(int ttris);
int					run(char *arg);
void				ft_puttab(char **ca);
int					verifend(t_tetri *lst, char **ca, int i);
int					verif_full(char **ca, int i);
void				init_place(char c, int i, char **ca);
int					resolv_recur(t_tetri *lst, char **ca,
						int (*f[2])(t_tetri *lst, char **carre, int *i, int j));
int					j_place(t_tetri *lst, char **carre, int *i, int j);
int					o_place(t_tetri *lst, char **carre, int *i, int j);
int					i_place(t_tetri *lst, char **carre, int *i, int j);
int					z_place(t_tetri *lst, char **carre, int *i, int j);
int					s_place(t_tetri *lst, char **carre, int *i, int j);
int					t_place(t_tetri *lst, char **carre, int *i, int j);
int					t_place_1(t_tetri *lst, char **carre, int *i, int j);
int					t_place_2(t_tetri *lst, char **carre, int *i, int j);
int					l_place(t_tetri *lst, char **carre, int *i, int j);
int					l_place_1(t_tetri *lst, char **carre, int *i, int j);
int					l_place_2(t_tetri *lst, char **carre, int *i, int j);
char				**resolv(t_tetri *lst);
size_t				lstlen(t_tetri *lst);
t_tetri				*creat_elem(char c, int rot);
t_tetri				*creat_lst(char *file);
int					add_elem(t_tetri **lst, t_tetri *new);
void				putlst(t_tetri *lst);
void				del_lst(t_tetri **lst);
int					i_search(char *buf);
int					o_search(char *buf);
int					t_search(char *buf);
int					l_search(char *buf);
int					j_search(char *buf);
int					z_search(char *buf);
int					s_search(char *buf);
int					tetris_check(char *str);

#endif
