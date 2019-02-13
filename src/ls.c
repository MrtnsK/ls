/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 13:03:48 by agissing          #+#    #+#             */
/*   Updated: 2019/02/13 14:09:41 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls(t_struct *tab, int rec)
{
	t_param		*tmp;

	get_childs(*tab->names, tab->opt, 0);
	if (tab->opt & OPT_LR)
		reverse_param(tab->names);
	tmp = *tab->names;
	while (tmp)
	{
		if ((*tab->names)->next && !tab->nb && (tmp->ok || rec))
			ft_addtwostr(&tab->bf, (tmp)->name, ":\n");
		else if (tab->nb && (tmp->ok || rec))
		{
			ft_addchar(&tab->bf, '\n');
			ft_addtwostr(&tab->bf, (tmp)->name, ":\n");
		}
		if (tmp->ok == 2 && tab->opt & OPT_L)
			total(&tab->bf, *(tmp)->child);
		if (tmp->ok && tab->opt & OPT_L)
			list_print(*(tmp)->child, tab->opt, &tab->bf);
		else if (tmp->ok)
			simple_print(*(tmp)->child, &tab->bf, tab->opt);
		tmp->ok ? tab->nb++ : 0;
		tmp = (tmp)->next;
	}
	ft_putbuff(&tab->bf);
}

int		is_point(char *name)
{
	return ((name[0] == '.' && !name[1])
			|| (name[0] == '.' && name[1] && name[1] == '.' && !name[2]));
}

void	do_ls_rec(t_struct *new, t_struct *tab)
{
	t_lst		*tmp1;

	while (*tab->names)
	{
		if (!(new->names = (t_param **)ft_memalloc(sizeof(t_param *))))
			return ;
		ft_sort((*tab->names)->child, tab->opt);
		if (!(*new->names = NULL) && tab->opt & OPT_LR)
			reverse_lst((*tab->names)->child);
		while (*(*tab->names)->child)
		{
			if (S_ISDIR((*(*tab->names)->child)->stat.st_mode)
				&& !is_point(ft_title((*(*tab->names)->child)->name, 0)))
			{
				ft_param_push_back(new->names, (*(*tab->names)->child)->name);
				ls_rec(new, 1);
			}
			tmp1 = *(*tab->names)->child;
			*(*tab->names)->child = (*(*tab->names)->child)->next;
			free(tmp1->name);
			free(tmp1);
		}
		ft_free(new->names);
		free(new->names);
		*tab->names = (*tab->names)->next;
	}
}

void	ls_rec(t_struct *tab, int rec)
{
	t_struct	new;
	t_param		*tmp;

	tmp = *tab->names;
	ft_free_lst(*tab->names);
	ls(tab, rec);
	if (tab->opt & OPT_LR)
		get_childs(tmp, tab->opt, 1);
	new.opt = tab->opt;
	new.nb = tab->nb;
	new.bf = tab->bf;
	do_ls_rec(&new, tab);
	ft_free(tab->names);
	ft_free(&tmp);
}

int		link_pointer(t_buf *i, char *name)
{
	char	*buf;

	buf = ft_strnew(500);
	ft_addstr(i, " -> ");
	readlink(name, buf, 500);
	ft_addstr(i, buf);
	free(buf);
	return (1);
}
