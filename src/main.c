/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:57:47 by kemartin          #+#    #+#             */
/*   Updated: 2019/01/08 13:10:19 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	int			i;
	int			j;
	t_struct	*tab;

	if (!(tab = (t_struct *)malloc(sizeof(t_struct))))
		return (0);
	i = 1;
	j = 0;
	while (i < ac)
	{
		if (av[i][0] == '-')
			options(av[i], tab);
		else if (av[i][0] != '-')
			tab->file[j++] = ft_strcpy(tab->file[j], av[i]);
		i++;
	}
	return (0);
}
