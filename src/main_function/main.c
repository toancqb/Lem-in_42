/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:25:04 by qtran             #+#    #+#             */
/*   Updated: 2019/07/12 14:12:17 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"
#include "ft_lib_lem_in.h"
#include "ft_find_solution.h"

static inline void	ft_print_info(t_global *g)
{
	write(1, "----INFORMATION----\n", 20);
	ft_printf("Number of ants: %d\n", g->nb_ant);
	ft_printf("Number of rooms adjacent to start: %d\n", g->start->nb_link);
	ft_printf("Number of paths taken: %d\n", g->n_path ? g->n_path : 1);
	ft_printf("Number of steps: %d\n", g->solution
			? g->solution->n_total_step : 1);
	write(1, "------------------\n", 20);
}

static inline int	ft_is_next_to(t_room *room, t_room *target)
{
	t_roomlst	*link;

	link = *(room->link);
	while (link != NULL)
	{
		if (target == link->r)
			return (1);
		link = link->next;
	}
	return (0);
}

static inline void	ft_print_adjacent_end(t_global *g)
{
	int		nb_ant;

	nb_ant = 1;
	while (nb_ant <= g->nb_ant)
	{
		ft_printf("L%d-%s ", nb_ant, g->end->name);
		nb_ant++;
	}
	write(1, "\n", 1);
}

static inline void	lem_in_simple(int opt)
{
	t_global *g;

	g = ft_global_init();
	if (ft_input_parsing(g, opt) == -1)
	{
		ft_putstr("Error\n");
		ft_global_free(&g);
		exit(0);
	}
	if (ft_is_next_to(g->start, g->end))
		ft_print_adjacent_end(g);
	else
	{
		ft_find_global_solution(g);
		if (opt & OPT_P)
			ft_print_solution(g->solution);
		if (print_lem_in_simple(g) == -1)
			ft_putstr("Error\n");
	}
	if (opt & OPT_I)
		ft_print_info(g);
	ft_global_free(&g);
}

int					main(int argc, char *argv[])
{
	int		opt;

	opt = ft_opt_input_parsing(argc, argv);
	lem_in_simple(opt);
	return (0);
}
