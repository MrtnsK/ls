/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:49:26 by kemartin          #+#    #+#             */
/*   Updated: 2019/01/08 19:33:19 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_lst	*ft_create_elem(char *name)
{
	t_lst		*lst;
	t_stat		*stats;

	stats = NULL;
	if (!(lst = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	lst->next = NULL;
	lst->name = ft_strdup(name);
	if (!(stat(name, stats)))
		return (NULL);
	lst->stat = stats;
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
