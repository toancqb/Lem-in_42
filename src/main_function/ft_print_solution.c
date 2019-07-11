/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_solution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 14:06:09 by gly               #+#    #+#             */
/*   Updated: 2019/07/11 15:16:42 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_find_solution.h"

void	ft_print_solution(t_solution *solution)
{
	t_pathlst	*pathlst;
	t_roomlst	*path;
	int			i;
	int			j;

	pathlst = solution->pathlst;
	i = 1;
	while (pathlst != NULL)
	{
		ft_printf("Path %d:\n", i);
		ft_printf("Number of ants in the path: %d\n", pathlst->nb_ant);
		ft_printf("Number of rooms in the path: %d\n", pathlst->n_step);
		path = pathlst->path;
		j = 0;
		while (j < pathlst->n_step)
		{
			ft_printf("[%s]->", path->r->name);
			path = path->next;
			j++;
		}
		ft_printf("[%s]\n", path->r->name);
		i++;
		pathlst = pathlst->next;
	}
}
