/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:49:33 by kzennoun          #+#    #+#             */
/*   Updated: 2023/02/11 21:36:10 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS
#define FT_LS

#include "libft/libft.h"
#include <stdbool.h>

enum sort_type { None, Alpha, Access, Modif };

typedef struct s_flags
{
	//mandatory
	bool all; //-a --all
	bool long_listing; //-l
	bool sort_modif_time; //-t
	bool recursive; //-R
	bool reverse; //-r

	//bonus
//	bool almost_all; //-A --almost-all
	bool author; //--author (needs -l(others like -g might work, need more testing))
	//bool ignore_backup; //-B, --ignore-backups
	bool no_owner; //-g
	bool no_group; //-o (-G excluded)
	bool sort_access_time; // -u (shitty combos -ul/-ult see man)
	bool no_sort; //-f     do not sort, enable -aU, disable -ls --color
} t_flags;

typedef struct s_args
{
	int *paths;
	enum sort_type sort;

	bool long_listing;
	bool recursive;
	bool all;
	bool reverse;
//	bool almost_all;

	bool author;
	bool no_owner;
	bool no_group;

} t_args;




#endif