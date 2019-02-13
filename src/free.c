/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 12:31:30 by agissing          #+#    #+#             */
/*   Updated: 2019/02/13 13:50:57 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_free_lst(t_param *tab)
{
	t_param	*tmp;
	t_lst	*tmp1;

	tmp = tab;
	while (tmp)
	{
		while (*tmp->child)
		{
			tmp1 = *tmp->child;
			free((*tmp->child)->name);
			*tmp->child = (*tmp->child)->next;
			free(tmp1);
		}
		tmp = tmp->next;
	}
	*tab->child = NULL;
}

void	ft_free(t_param **tab)
{
	t_param	*tmp;
	t_lst	*tmp1;

	while (*tab)
	{
		tmp = *tab;
		while (*tmp->child)
		{
			tmp1 = *tmp->child;
			free((*tmp->child)->name);
			*tmp->child = (*tmp->child)->next;
			free(tmp1);
		}
		free(tmp->child);
		*tab = (*tab)->next;
		free(tmp);
	}
	free(*tab);
}
