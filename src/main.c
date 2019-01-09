/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:57:47 by kemartin          #+#    #+#             */
/*   Updated: 2019/01/09 19:03:22 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	showme(t_lst *lst)
{
	while (lst)
	{
		printf("name: %s\n", lst->name);
		printf("inode: %llu\n", lst->stat->st_ino);
		printf("owner: %u\n", lst->stat->st_uid);
		printf("group: %u\n", lst->stat->st_gid);
		printf("perms: %o\n", lst->stat->st_mode & (S_IRWXU | S_IRWXG | S_IRWXO));
		printf("links: %d\n", lst->stat->st_nlink);
		printf("size: %lld\n", lst->stat->st_size); /* you may use %lld */
		printf("atime: %s", ctime(&lst->stat->st_atime));
		printf("mtime: %s", ctime(&lst->stat->st_mtime));
		printf("ctime: %s", ctime(&lst->stat->st_ctime));
		printf("\n\n\n");
		lst = lst->next;
	}
}


int		is_file(char *name)
{
	DIR*		fd;

	if ((fd = opendir(name)) && closedir(fd))
    	return (0);
	if (errno == ENOTDIR)
    	return (1);
    return (-1);
}

int		main(int ac, char **av)
{
	int			i;
	int			j;
	t_struct	*tab;
	t_lst		*lst;

	if (!(tab = (t_struct *)malloc(sizeof(t_struct)))
	&& !(lst = malloc(sizeof(t_lst))))
		return (0);
	i = 1;
	j = 0;
	while (i < ac)
	{
		if (av[i][0] == '-')
			options(av[i], tab);
		else if (av[i][0] != '-')
			ft_list_push_back(&lst, av[i]);
		i++;
	}
	tab->lst = &lst;
	showme(lst);
	free(tab);
	return (0);
}
