/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 13:47:57 by agissing          #+#    #+#             */
/*   Updated: 2019/01/25 18:48:50 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		total(t_buf *i, t_lst *lst)
{
	int		tot;

	tot = 0;
	if (!lst)
		return ;
	while (lst)
	{
		tot += lst->stat.st_blocks;
		lst = lst->next;
	}
	ft_addstr(i, "total ");
	ft_addnbr(i, tot);
	ft_addchar(i, '\n');
}
