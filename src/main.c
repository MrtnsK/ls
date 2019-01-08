/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:57:47 by kemartin          #+#    #+#             */
/*   Updated: 2019/01/08 19:25:04 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

	if (!(tab = (t_struct *)malloc(sizeof(t_struct))) && !(tab->lst = malloc(sizeof(t_lst))))
		return (0);
	i = 1;
	j = 0;
	while (i < ac)
	{
		if (av[i][0] == '-')
			options(av[i], tab);
		else if (av[i][0] != '-')
			ft_list_push_back(tab->lst, av[i]);
		i++;
	}
	free(tab);
	return (0);
}
