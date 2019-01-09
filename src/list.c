/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:49:26 by kemartin          #+#    #+#             */
/*   Updated: 2019/01/09 19:09:32 by kemartin         ###   ########.fr       */
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

char	*ft_title(char *title)
{
	int		i;

	while (ft_strchr(title, '/'))
		title = ft_strchr(title, '/') + 1;
	i = ft_strlen(title);
	while (i && title[i] == '.' ? title[i] = '\0' : 1)
		i--;
	return (title);
}

t_lst	*ft_create_elem(char *name)
{
	t_lst		*lst;
	struct stat	stbuf;

	if ((!(lst = (t_lst *)malloc(sizeof(t_lst)))))
		return (NULL);
	lst->next = NULL;
	lst->name = ft_strdup(name);
	if (stat(name, &stbuf) < 0)
		return (files_err(ft_title(name)));
	lst->stat = &stbuf;
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
