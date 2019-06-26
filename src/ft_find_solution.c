/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_solution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 16:11:53 by gly               #+#    #+#             */
/*   Updated: 2019/06/25 18:52:19 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_findsolution.h"

inline static int ft_optimize_solution(t_global *glob, t_solution *solution)
{
	int			n_step;
	t_solution	*tmp;

	n_step = ft_calculate_step(glob->n + 1, solution);
	if (n_step <= glob->n_step)
	{
		glob->n_step = n_step;
		glob->n++;
		ft_free_solution(&(glob->solution));
		glob->solution = solution;
		ft_change_path_matrix(glob);
		return (0);
	}
	ft_free_solution(&solution);
	return (1);
}

inline static int		ft_find_solution_for_n_path(t_glob *glob, int n_path,
		t_solution *solution)
{
	int			ret;

	if ((ret = ft_find_path(glob, n_path)) == -1)
		return (-1);
	else if (ret == 0)
		ft_printf("DID not find a solution for %d paths\n", n_path);
	else
	{
		if ((ret = ft_get_path(glob, solution, n_path)) == -1)
			return (-1);
	}
	return (0);
}

int		ft_find_global_solution(t_glob *glob)
{
	t_solution	*solution;
	int			i;
	int			ret;

	i = 0;
	if (!(solution = ft_solution_new()))
		return (-1);
	while (i < 4)
	{
		if ((ret = ft_find_solution_for_n_path(glob, i + 1,
						solution)) != 0)
			return (ret);
		if (ft_optimize_solution(glob, i + 1, solution))
			return (0);
		i++;
	}
	return (0);
}
