/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 19:47:31 by kemartin          #+#    #+#             */
/*   Updated: 2019/01/15 21:27:50 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*cut_time_opt(char *str)
{
	int		i;
	int		j;
	char	*date;

	if (!(date = (char *)malloc(sizeof(char) * 17)))
		return (NULL);
	i = 4;
	j = 0;
	while (i < 16 && str[i])
		date[j++] = str[i++];
	date[j] = '\0';
	return (date);
}

//lst->stat.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO)

char	*write_perms(int perm, char *name)
{
	char	*str;

	if (!(str = (char*)malloc(sizeof(char) * 11)))
		return (NULL);
	if (is_file(name) == 0)
		str[0] = 'd';
	else
		str[0] = '-';
	(void)perm;
	return (str);
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
