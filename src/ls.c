/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 19:21:24 by kemartin          #+#    #+#             */
/*   Updated: 2019/01/09 19:54:03 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		simple_ls(t_struct *tab)
{
	DIR				*d;
	struct dirent	*dir;
	t_lst			*lst;

	if (!(lst = malloc(sizeof(t_lst))))
		return (0);
	d = opendir(".");
	if (d)
		while ((dir = readdir(d)))
		{
			if (dir->d_name[0] != '.')
				printf("%s\t", dir->d_name);
				//ft_list_push_back(&lst, dir->d_name);
		}
	tab->lst = &lst;
	closedir(d);
	return (0);
}

int		ls_opt_a(t_struct *tab)
{
	DIR				*d;
	struct dirent	*dir;

	(void)tab;
	d = opendir(".");
	if (d)
		while ((dir = readdir(d)))
			printf("%s\t", dir->d_name);
	closedir(d);
	return (0);
}
