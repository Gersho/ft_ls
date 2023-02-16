/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:01:50 by kzennoun          #+#    #+#             */
/*   Updated: 2023/02/16 20:01:28 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

#include <stdio.h>
#include <stdlib.h>

void fatal_error(char *s)
{
	perror(s);
	exit(-1);
}

void free_args_fatal(t_args *args, char *s)
{
	if(args && args->paths)
		free(args->paths);
	if(args)
		free(args);
	fatal_error(s);
}