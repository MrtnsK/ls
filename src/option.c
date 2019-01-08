/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 12:09:32 by kemartin          #+#    #+#             */
/*   Updated: 2019/01/08 13:01:57 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_opts(char c)
{
	return (c == 'l' || c == 'R' || c == 'a' || c == 'r' || c == 't');
}

void	options(char *str, t_struct *tab)
{
	int			i;
	int			j;

	i = 1;
	j = ft_strlen(tab->opt);
	while (str[i])
	{
		if (is_otps(str[i]))
			tab->opt[j++] = str[i];
		i++;
	}
}
