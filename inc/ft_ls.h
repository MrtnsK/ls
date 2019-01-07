/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:56:16 by kemartin          #+#    #+#             */
/*   Updated: 2019/01/07 17:10:10 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <libc.h>
# include <errno.h>
# include <unistd.h>

struct		s_stat
{
    dev_t		st_dev;      /* ID du périphérique contenant le fichier */
    ino_t		st_ino;      /* Numéro inœud */
    mode_t		st_mode;     /* Protection */
    nlink_t		st_nlink;    /* Nb liens matériels */
    uid_t		st_uid;      /* UID propriétaire */
    gid_t		st_gid;      /* GID propriétaire */
    dev_t		st_rdev;     /* ID périphérique (si fichier spécial) */
    off_t		st_size;     /* Taille totale en octets */
    blksize_t	st_blksize;  /* Taille de bloc pour E/S */
    blkcnt_t	st_blocks;   /* Nombre de blocs alloués */
    time_t		st_atime;    /* Heure dernier accès */
    time_t		st_mtime;    /* Heure dernière modification */
    time_t		st_ctime;    /* Heure dernier changement état */
}			t_stat;


#endif
 