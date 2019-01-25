/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 12:57:16 by agissing          #+#    #+#             */
/*   Updated: 2019/01/25 12:57:51 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_g(t_lst *lst, t_buf *i)
{
	if (S_ISDIR(lst->stat.st_mode))
		ft_addstr(i, "\033[1;36m");
	else if (S_ISLNK(lst->stat.st_mode))
		ft_addstr(i, "\033[0;35m");
	else if (lst->stat.st_mode & S_IXUSR)
		ft_addstr(i, "\033[0;31m");
	else if (S_ISCHR(lst->stat.st_mode))
		ft_addstr(i, "\033[43m\033[34m");
	else if (S_ISBLK(lst->stat.st_mode))
		ft_addstr(i, "\033[46m\033[34m");
	ft_addstr(i, ft_title(lst->name));
	ft_addstr(i, "\033[0m");
}

void	simple_print(t_lst *lst, t_buf *i, char opt)
{
	ft_sort(&lst, opt);
	if (opt & OPT_LR)
		reverse_lst(&lst);
	while (lst)
	{
		opt & OPT_G ? print_g(lst, i) : ft_addstr(i, ft_title(lst->name));
		if (lst->next)
			ft_addstr(i, "  ");
		else
			ft_addchar(i, '\n');
		lst = lst->next;
	}
}

void	list_print(t_lst *lst, char opt, t_buf *i)
{
	ft_sort(&lst, opt);
	if (opt & OPT_LR)
		reverse_lst(&lst);
	while (lst)
	{
		leading(11, write_perms(lst->stat.st_mode), i);
		leading_nbr(2, lst->stat.st_nlink, i);
		leading(10, lst->pswd->pw_name, i);
		leading(12, lst->grp->gr_name, i);
		leading_nbr(3, lst->stat.st_size, i);
		leading(13, cut_time_opt(ctime(&lst->stat.st_ctime)), i);
		opt & OPT_G ? print_g(lst, i) : ft_addstr(i, ft_title(lst->name));
		ft_addchar(i, '\n');
		lst = lst->next;
	}
}
