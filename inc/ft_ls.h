/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:56:16 by kemartin          #+#    #+#             */
/*   Updated: 2019/01/09 19:43:43 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <libc.h>
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>

# define OPT_L 1
# define OPT_UR 2
# define OPT_A 4
# define OPT_LR 8
# define OPT_T 16


typedef struct stat	t_stat;
typedef struct dir	t_dir;
// typedef	struct		s_dir
// {
//     ino_t			d_ino;       /* numéro d'inœud */
//     off_t			d_off;       /* décalage jusqu'à la dirent suivante */
//     unsigned short	d_reclen;    /* longueur de cet enregistrement */
//     unsigned char	d_type;      /* type du fichier */
//     char			d_name[256]; /* nom du fichier */
// }					t_dir;

typedef struct		s_lst
{
	char			*name;
	t_stat			*stat;
	t_dir			*dir;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_struct
{
	char			opt;
	t_lst			**lst;
}					t_struct;

t_lst				*ft_create_elem(char *name);
void				ft_list_push_back(t_lst **lst, char *name);
int					is_file(char *name);
int					is_opts(char c);
void				options(char *str, t_struct *tab);
int					simple_ls(t_struct *tab);
int					ls_opt_a(t_struct *tab);

#endif
 