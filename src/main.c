/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:57:47 by kemartin          #+#    #+#             */
/*   Updated: 2019/01/17 20:16:47 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_file(char *name)
{
	DIR			*fd;

	if ((fd = opendir(name)) && closedir(fd))
		return (0);
	if (errno == ENOTDIR)
		return (1);
	return (-1);
}

void	wich_ls(t_struct **tab)
{
	if (((*tab)->opt & OPT_A) && ((*tab)->opt & OPT_L))
		ls_opt_la(*tab);
	else if ((*tab)->opt & OPT_A)
		ls_opt_a(*tab);
	else if ((*tab)->opt & OPT_L)
		ls_opt_l(*tab);
	else
		simple_ls(*tab);
}

int		main(int ac, char **av)
{
	int			i;
	t_struct	*tab;
	t_lst		*lst;

	if (!(tab = (t_struct *)malloc(sizeof(t_struct)))
	&& !(lst = malloc(sizeof(t_lst))))
		return (0);
	i = 1;
	tab->opt = 0;
	while (i < ac)
	{
		if (av[i][0] == '-')
			options(av[i], tab);
		else if (av[i][0] != '-')
			ft_list_push_back(&lst, av[i]);
		i++;
	}
	tab->lst = &lst;
	wich_ls(&tab);
	free(tab);
	return (0);
}
