/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 19:21:24 by kemartin          #+#    #+#             */
/*   Updated: 2019/01/23 17:43:15 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	files_err(char *name)
{
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(name, 2);
	ft_putendl_fd(": No such file or directory", 2);
}	

void	get_childs(t_param *p, char opt)
{
	DIR				*d;
	struct dirent	*dir;

	while (p)
	{
		if ((d = opendir(p->name)))
		{
			while ((dir = readdir(d)))
				if (opt & OPT_A || dir->d_name[0] != '.')
					ft_lst_push_back(p->child, dir->d_name, p->name);
			closedir(d);
		}
		else
		{
			p->ok = 0;
			files_err(p->name);
		}
		p = p->next;
	}
}

void	print_G(t_lst *lst)
{
	if (S_ISDIR(lst->stat.st_mode))
		printf("\033[1;36m");
	else if (S_ISLNK(lst->stat.st_mode))
		printf("\033[0;35m");
	else if (lst->stat.st_mode & S_IXUSR)
		printf("\033[0;31m");
	else if (S_ISCHR(lst->stat.st_mode))
		printf("\033[43m\033[34m");
	else if (S_ISBLK(lst->stat.st_mode))
		printf("\033[46m\033[34m");
	printf("%s", ft_title(lst->name));
	printf("\033[0m");
}

void	simple_print(t_lst *lst, char opt)
{
	ft_sort(&lst, opt);
	if (opt & OPT_LR)
		reverse_lst(&lst);
	while (lst)
	{
		opt & OPT_G ? print_G(lst) \
		: ft_putstr(ft_title(lst->name));
		if (lst->next)
			ft_putstr("  ");
		else
			ft_putchar('\n');
		lst = lst->next;
	}
}

void	list_print(t_lst *lst, char opt)
{
	ft_sort(&lst, opt);
	if (opt & OPT_LR)
		reverse_lst(&lst);
	while (lst)
	{
		printf("%s ", write_perms(lst->stat.st_mode));
		printf("%3d", lst->stat.st_nlink);
		printf("%9s ", lst->pswd->pw_name);
		printf("%11s ", lst->grp->gr_name);
		printf("%6lld ", lst->stat.st_size);
		printf("%s ", cut_time_opt(ctime(&lst->stat.st_ctime)));
		opt & OPT_G ? print_G(lst) \
		: printf("%s", ft_title(lst->name));
		printf("\n");
		lst = lst->next;
	}
}
