/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:02:40 by kzennoun          #+#    #+#             */
/*   Updated: 2023/02/16 22:22:42 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void parse_long_option(t_args *args, char *str)
{
	int len = ft_strlen(str);

	if (str[2] == '\0')
		args->options = false;
	else if (!ft_strncmp("--version", str, len))
		show_version();
	else if (!ft_strncmp("--help", str, len))
		show_help();
	else if (!ft_strncmp("--author", str, len))
		args->author = true;
	else if (!ft_strncmp("--all", str, len))
		args->all = true;
}

void parse_option(t_args *args, char *str)
{
	int i = 1;

	
}

void parse_arg(t_args *args, char *str)
{
	if(str[0] == '-' && str[1] && args->options)
	{
		if (str[1] == '-')
			parse_long_option(args, str);
		else
			parse_option(args, str);
	}
	else
		args_add_path(args, str);
}

t_args* parsing(int ac, char** av)
{
	t_args *args = args_default();
	int i = 1;

	while(i < ac)
	{
		parse_arg(args, av[i]);
		i++;		
	}
	return args;
}