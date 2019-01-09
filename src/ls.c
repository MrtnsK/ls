/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 19:21:24 by kemartin          #+#    #+#             */
/*   Updated: 2019/01/09 20:21:51 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_struct	*simple_ls(t_struct *tab)
{
	DIR				*d;
	struct dirent	*dir;
	t_lst			*lst;

	if (!(lst = malloc(sizeof(t_lst))))
		return (0);
	lst->next = NULL;
	d = opendir(".");
	if (d)
		while ((dir = readdir(d)))
			if (dir->d_name[0] != '.')
				ft_list_push_back(&lst, dir->d_name);
	tab->lst = &lst;
	closedir(d);
	ft_lstsort(&lst);
	while (lst)
	{
		ft_putstr(lst->name);
		if (lst->next)
			ft_putchar(' ');
		else
			ft_putchar('\n');
		lst = lst->next;
	}
	return (tab);
}

t_struct	*ls_opt_a(t_struct *tab)
{
	DIR				*d;
	struct dirent	*dir;
	t_lst			*lst;

	if (!(lst = malloc(sizeof(t_lst))))
		return (0);
	lst->next = NULL;
	d = opendir(".");
	if (d)
		while ((dir = readdir(d)))
			ft_list_push_back(&lst, dir->d_name);
	closedir(d);
	tab->lst = &lst;
	return (tab);
}
