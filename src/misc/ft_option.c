/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 14:44:29 by gly               #+#    #+#             */
/*   Updated: 2019/07/11 14:48:33 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_lib_lem_in.h"

static inline int	process_opt(int opt, char *str)
{
	if (str)
	{
		if (str[0] != '-')
			ft_strerror("Usage: ./lem-in -option < map.txt");
		else
		{
			str++;
			while (*str != '\0')
			{
				if (*str == 'i')
					opt |= OPT_I;
				else if (*str == 's')
					opt |= OPT_S;
				else if (*str == 'p')
					opt |= OPT_P;
				str++;
			}
		}
	}
	return (opt);
}

int				 	ft_opt_input_parsing(int argc, char **argv)
{
	int		i;
	int		opt;

	opt = 0;
	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			opt = process_opt(opt, argv[i]);
			i++;
		}
	}
	return (opt);
}
