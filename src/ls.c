/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 19:21:24 by kemartin          #+#    #+#             */
/*   Updated: 2019/01/16 20:33:52 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_struct	*simple_ls(t_struct *tab)
{
	DIR				*d;
	struct dirent	*dir;
	t_lst			**lst;

	if (!(lst = malloc(sizeof(t_lst *))))
		return (0);
	*lst = NULL;
	d = opendir(".");
	if (d)
		while ((dir = readdir(d)))
			if (dir->d_name[0] != '.')
				ft_list_push_back(lst, dir->d_name);
	tab->lst = lst;
	closedir(d);
	ft_sort(lst);
	while (*lst)
	{
		ft_putstr((*lst)->name);
		if ((*lst)->next)
			ft_putchar(' ');
		else
			ft_putchar('\n');
		*lst = (*lst)->next;
	}
	return (tab);
}

t_struct	*ls_opt_a(t_struct *tab)
{
	DIR				*d;
	struct dirent	*dir;
	t_lst			**lst;

	if (!(lst = malloc(sizeof(t_lst *))))
		return (0);
	*lst = NULL;
	d = opendir(".");
	if (d)
		while ((dir = readdir(d)))
			ft_list_push_back(lst, dir->d_name);
	tab->lst = lst;
	closedir(d);
	ft_sort(tab->lst);
	while (*lst)
	{
		ft_putstr((*lst)->name);
		if ((*lst)->next)
			ft_putstr("  ");
		else
			ft_putchar('\n');
		*lst = (*lst)->next;
	}
	return (tab);
}

t_struct	*ls_opt_l(t_struct *tab)
{
	DIR				*d;
	struct dirent	*dir;
	t_lst			**lst;

	if (!(lst = malloc(sizeof(t_lst *))))
		return (0);
	*lst = NULL;
	d = opendir(".");
	if (d)
		while ((dir = readdir(d)))
			ft_list_push_back(lst, dir->d_name);
	tab->lst = lst;
	closedir(d);
	ft_sort(lst);
	while (*lst)
	{
		if (is_file((*lst)->name) == 1)
		{
			printf("%s ", write_perms((*lst)->stat.st_mode));
			printf("%4d", (*lst)->stat.st_nlink);
			printf("%10s ", (*lst)->pswd->pw_name);
			printf("%11s ", (*lst)->grp->gr_name);
			printf("%6lld ", (*lst)->stat.st_size);
			printf("%s ",  cut_time_opt(ctime(&(*lst)->stat.st_ctime)));
			printf("%s", (*lst)->name);
			printf("\n");
		}
		*lst = (*lst)->next;
	}
	return (tab);
}

t_struct	*ls_opt_la(t_struct *tab)
{
	DIR				*d;
	struct dirent	*dir;
	t_lst			**lst;

	if (!(lst = malloc(sizeof(t_lst *))))
		return (0);
	*lst = NULL;
	d = opendir(".");
	if (d)
		while ((dir = readdir(d)))
			ft_list_push_back(lst, dir->d_name);
	tab->lst = lst;
	closedir(d);
	ft_sort(lst);
	while (*lst)
	{
		printf("%s ", write_perms((*lst)->stat.st_mode));
		printf("%4d", (*lst)->stat.st_nlink);
		printf("%10s ", (*lst)->pswd->pw_name);
		printf("%11s ", (*lst)->grp->gr_name);
		printf("%6lld ", (*lst)->stat.st_size);
		printf("%s ",  cut_time_opt(ctime(&(*lst)->stat.st_ctime)));
		printf("%s", (*lst)->name);
		printf("\n");
		*lst = (*lst)->next;
	}
	return (tab);
}
