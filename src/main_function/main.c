/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:25:04 by qtran             #+#    #+#             */
/*   Updated: 2019/07/05 10:52:06 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib_lem_in.h"
#include "ft_find_solution.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	lem_in_simple(t_option *opt)
{
	t_global *g;

	g = ft_global_init();
	ft_input_parsing(g, opt);
	ft_find_global_solution(g);
	if (opt->i)
	{
		printf("Le nombre de fourmi est %d\n", g->nb_ant);
		printf("START %s \n", g->start->name);
		printf("End is %s\n", g->end->name);
		print_solution(g);
	}
	print_lem_in_simple(g);
	ft_global_free(&g);
}

int main(int argc, char *argv[])
{
	t_option *opt;

	opt = ft_opt_init();
	ft_opt_input_parsing(opt, argc, argv);
	lem_in_simple(opt);
	return (0);
}
