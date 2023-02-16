/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_args.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:09:31 by kzennoun          #+#    #+#             */
/*   Updated: 2023/02/16 21:30:49 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int args_path_len(t_args *args)
{
	char **tmp = args->paths;
	int ret = 0;

	if(!tmp)
		return ret;
	while(tmp[ret])
		ret++;
	return ret;
}

void args_add_path(t_args *args, char *new_path)
{
	int i = 0;
	char **tmp = malloc(sizeof(char*) * (args_path_len(args) + 1));

	if(!tmp)
		free_args_fatal(args, "malloc failed in args_add_path()");
	while(args->paths && args->paths[i])
	{
		tmp[i] = args->paths[i];
		i++;
	}
	tmp[i] = new_path;
}

t_args* args_default()
{	
	t_args *ret = malloc(sizeof(t_args));
	
	if (!ret)
		fatal_error("malloc failed in args_default()");
	ret->paths = NULL;
	ret->sort = Alpha;

	ret->options = true;

	ret->sort_modif_time = false;
	ret->sort_access_time = false;
	ret->no_sort = false;

	ret->recursive = false;
	ret->all = false;
	ret->reverse = false;
	ret->author = false;
	ret->owner = true;
	ret->group = true;
}