/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_solution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 16:11:53 by gly               #+#    #+#             */
/*   Updated: 2019/06/28 11:58:45 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_findsolution.h"

inline static int	ft_optimize_solution(t_global *glob, t_solution *solution)
{
	int			n_step;
	t_solution	*tmp;

	if ((n_step = ft_calculate_step(glob->n_path + 1, solution)) == -1)
	{
		ft_free_solution(&solution);
		return (1);
	}
	if (glob->n_path == 0 || n_step <= glob->n_step)
	{
		glob->n_step = n_step;
		if (glob->n_path != 0)
			ft_free_solution(&(glob->solution));
		glob->n_path++;
		glob->solution = solution;
		ft_adapt_glob_to_new_solution(glob);
		return (0);
	}
	ft_free_solution(&solution);
	return (1);
}

inline static int	ft_find_solution_for_n_path(t_glob *glob,
		t_solution *solution)
{
	int			ret;

	if ((ret = ft_find_path(glob)) == -1)
		return (-1);
	else if (ret == 1)
		ft_printf("DID not find a solution for %d paths\n", glob->n_path + 1);
	else
	{
		if ((ret = ft_get_path(glob, solution)) == -1)
			return (-1);
	}
	return (0);
}

int					ft_find_global_solution(t_glob *glob)
{
	t_solution	*solution;
	int			ret;

	if (!(solution = ft_solution_new()))
		return (-1);
	while (glob->n_path < 4)
	{
		if ((ret = ft_find_solution_for_n_path(glob, solution)) != 0)
			return (ret);
		if (ft_optimize_solution(glob, solution))
			return (0);
		(glob->n_path)++;
	}
	return (0);
}
