/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:25:04 by qtran             #+#    #+#             */
/*   Updated: 2019/07/11 15:14:38 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"
#include "ft_lib_lem_in.h"
#include "ft_find_solution.h"

/* error_3 , 4, 6, 11
 * in link, room1-room2; what if room1/room2 doesn't exist?
 *
 * sujet4
 * errors of print_lem_in: 5
 *
 */
static inline void	ft_print_info(t_global *g)
{
	write(1, "----INFORMATION----\n", 20);
	ft_printf("Number of ants: %d\n", g->nb_ant);
	ft_printf("Number of rooms adjacent to start: %d\n", g->start->nb_link);
	ft_printf("Number of paths taken: %d\n", g->n_path);
	ft_printf("Number of steps: %d\n", g->solution->n_total_step);
	write(1, "------------------\n", 20);
}

static inline void	lem_in_simple(int opt)
{
	t_global *g;

	g = ft_global_init();
	ft_input_parsing(g, opt);
	ft_find_global_solution(g);
	if (opt & OPT_P)
		ft_print_solution(g->solution);
	if (print_lem_in_simple(g) == -1)
		ft_putstr("Error\n");
	if (opt & OPT_I)
		ft_print_info(g);
	ft_global_free(&g);
}

int 				main(int argc, char *argv[])
{
	int		opt;

	opt = ft_opt_input_parsing(argc, argv);
	lem_in_simple(opt);
	return (0);
}
