/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:49:26 by kemartin          #+#    #+#             */
/*   Updated: 2019/01/17 20:21:55 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_lst	*files_err(char *name)
{
	ft_putstr("ft_ls: ");
	ft_putstr(name);
	ft_putendl(": No such file or directory");
	exit(0);
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

void	lstcpy(t_lst *new, t_lst *old)
{
	new->name = ft_strdup(old->name);
	if (stat(new->name, &new->stat) < 0)
		return ;
	new->pswd = getpwuid(new->stat.st_uid);
	new->grp = getgrgid(new->stat.st_gid);
}

void	ft_sort(t_lst **lst)
{
	t_lst	*tmp1;
	t_lst	*tmp2;
	t_lst	*tmp3;
	t_lst	*trie;

	tmp1 = (*lst);
	if (!(trie = malloc(sizeof(t_lst))))
		return ;
	while (tmp1)
	{
		tmp3 = tmp1;
		lstcpy(trie, tmp1);
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (ft_strcmp(trie->name, tmp2->name) > 0)
			{
				tmp3 = tmp2;
				lstcpy(trie, tmp3);
			}
			tmp2 = tmp2->next;
		}
		lstcpy(tmp3, tmp1);
		lstcpy(tmp1, trie);
		tmp1 = tmp1->next;
	}
}
