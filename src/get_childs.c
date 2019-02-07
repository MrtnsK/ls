/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_childs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 12:56:16 by agissing          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/01/26 14:05:57 by agissing         ###   ########.fr       */
=======
/*   Updated: 2019/01/25 19:29:23 by kemartin         ###   ########.fr       */
>>>>>>> e9d4ac9fa6d1640ca3cfd38183e2b91194b0c850
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_ok(char opt, char *name)
{
	return (opt & OPT_A || (opt & OPT_UA && (name[0] != '.'
	|| (name[1] && (name[1] != '.' || name[2])))) || name[0] != '.');
}

void	get_childs(t_param *p, char opt)
{
	DIR				*d;
	struct dirent	*dir;
	struct stat		buf;

	while (p)
	{
		if ((d = opendir(p->name)))
		{
			while ((dir = readdir(d)))
				if (is_ok(opt, dir->d_name))
					ft_lst_push_back(p->child, dir->d_name, p->name);
			closedir(d);
		}
		else
		{
			if ((lstat(p->name, &buf) < 0 && !(p->ok = 0)) || errno == EACCES)
				errno == EACCES ? files_eacces(p->name) : files_err(p->name);
			else
				ft_lst_push_back(p->child, p->name, "");
		}
		p = p->next;
	}
}
