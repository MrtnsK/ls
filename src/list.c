/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:49:26 by kemartin          #+#    #+#             */
/*   Updated: 2019/01/15 16:58:46 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_lst	*files_err(char *name)
{
	ft_putstr("ft_ls: ");
	ft_putstr(name);
	ft_putendl(": No such file or directory");
	return (NULL);
}	

t_lst	*ft_create_elem(char *name)
{
	t_lst		*lst;

	if ((!(lst = (t_lst *)malloc(sizeof(t_lst)))))
		return (NULL);
	lst->next = NULL;
	lst->name = ft_strdup(name);
	if (stat(name, &lst->stat) < 0)
		return (files_err(ft_title(name)));
	lst->pswd =	getpwuid(lst->stat.st_uid);
	lst->grp = getgrgid(lst->stat.st_gid);
	return (lst);
}

void	ft_list_push_back(t_lst **lst, char *name)
{
	if (*lst)
	{
		if ((*lst)->next)
			ft_list_push_back(&((*lst)->next), name);
		else
			(*lst)->next = ft_create_elem(name);
	}
	else
		(*lst) = ft_create_elem(name);
}

void	lstcpy(t_lst **new, t_lst **old)
{
	(*new) = (*old);
}

void	ft_sort(t_lst **lst)
{
	t_lst	*tmp1;
	t_lst	*tmp2;
	t_lst	*tmp3;
	t_lst	*trie;

	tmp1 = (*lst);
	while (tmp1)
	{
		tmp3 = tmp1;
		lstcpy(&trie, &tmp1);
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (ft_strcmp(trie->name, tmp2->name) > 0)
			{
				tmp3 = tmp2;
				lstcpy(&trie, &tmp3);
			}
			tmp2 = tmp2->next;
		}
		lstcpy(&tmp3, &tmp1);
		lstcpy(&tmp1, &trie);
		tmp1 = tmp1->next;
	}
}
