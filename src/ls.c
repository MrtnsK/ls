/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 13:03:48 by agissing          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/02/07 11:36:27 by agissing         ###   ########.fr       */
=======
/*   Updated: 2019/01/25 19:24:13 by kemartin         ###   ########.fr       */
>>>>>>> e9d4ac9fa6d1640ca3cfd38183e2b91194b0c850
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_point(char *name)
{
	name = ft_title(name, 0);
	return (name[0] == '.' && (!name[1] || (name[1] && name[1] == '.' && !name[2])));
}

void	ls(t_struct *tab)
{
	t_param		*tmp;

	get_childs(*tab->names, tab->opt);
	if (((tmp = *tab->names) || 1) && tab->opt & OPT_LR)
		reverse_param(tab->names);
	while (tmp)
	{
		if (tmp->ok)
		{
			if ((*tab->names)->next && !tab->nb)
				ft_addtwostr(&tab->bf, (tmp)->name, ":\n");
			else if (tab->nb)
			{
				ft_addchar(&tab->bf, '\n');
				ft_addtwostr(&tab->bf, (tmp)->name, ":\n");
			}
			if (tab->opt & OPT_L)
				list_print(*(tmp)->child, tab->opt, &tab->bf);
			else
				simple_print(*(tmp)->child, &tab->bf, tab->opt);
			tab->nb++;
		}
		tmp = (tmp)->next;
	}
	ft_putbuff(&tab->bf);
}

void	ls_rec(t_struct *tab)
{
	t_struct	new;

	ls(tab);
	new.opt = tab->opt;
	new.nb = tab->nb;
	new.bf = tab->bf;
	while (*tab->names)
	{
		if (!(new.names = (t_param **)malloc(sizeof(t_param *))))
			return ;
		ft_sort((*tab->names)->child, tab->opt);
		if (!(*new.names = NULL) && tab->opt & OPT_LR)
			reverse_lst((*tab->names)->child);
		while (*(*tab->names)->child)
		{
			if (S_ISDIR((*(*tab->names)->child)->stat.st_mode)
				&& !is_point((*(*tab->names)->child)->name))
			{
		 		ft_param_push_back(new.names, (*(*tab->names)->child)->name);
				ls_rec(&new);
			}
			*(*tab->names)->child = (*(*tab->names)->child)->next;
		}
		free(new.names);
		*tab->names = (*tab->names)->next;
	}
}

int		link_pointer(t_buf *i, char *name)
{
	char	*buf;

	buf = ft_strnew(500);
	ft_addstr(i, " -> ");
	readlink(name, buf, 500);
	ft_addstr(i, buf);
	return (1);
}
