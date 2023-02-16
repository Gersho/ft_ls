/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:49:33 by kzennoun          #+#    #+#             */
/*   Updated: 2023/02/16 21:30:38 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS
#define FT_LS

#include "libft/libft.h"
#include <stdbool.h>

enum sort_type { None, Alpha, Access, Modif };

// typedef struct s_flags
// {
// 	//mandatory
// 	bool all; //-a --all
// 	bool long_listing; //-l
// 	bool sort_modif_time; //-t
// 	bool recursive; //-R
// 	bool reverse; //-r

// 	//bonus
// 	bool author; //--author (needs -l(others like -g might work, need more testing))
// 	bool no_owner; //-g
// 	bool no_group; //-o (-G excluded)
// 	bool sort_access_time; // -u (shitty combos -ul/-ult see man)
// 	bool no_sort; //-f     do not sort, enable -aU, disable -ls --color
// } t_flags;

typedef struct s_args
{
	char **paths;
	enum sort_type sort;

	//used to handle -- end of options flag
	bool options;

	//used during parsing only to choose sort_type
	bool sort_modif_time; //-t
	bool sort_access_time; // -u (shitty combos -ul/-ult see man)
	bool no_sort; //-f     do not sort, enable -aU, disable -ls --color

	//used during printing logic
	bool long_listing;//-l
	bool recursive; //-R
	bool all;//-a --all
	bool reverse; //-r
	bool author;//--author (needs -l(others like -g might work, need more testing))
	bool owner;//-g (NO owner)
	bool group; //-o (-G excluded) NO group

} t_args;

//parsing
t_args* parsing(int ac, char** av);

//t_args
t_args* args_default();
void args_add_path(t_args *args, char *new_path);

//error
void fatal_error(char *s);
void free_args_fatal(t_args *args, char *s);

#endif