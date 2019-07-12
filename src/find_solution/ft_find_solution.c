/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_solution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 16:11:53 by gly               #+#    #+#             */
/*   Updated: 2019/07/12 16:20:48 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_find_solution.h"

inline static int	ft_r_status_init(t_global *glob)
{
	if (!(glob->r_status = ft_strnew(glob->nb_room)))
		return (-1);
	glob->r_status[glob->start->i] |= ACTIVISIT;
	return (0);
}

inline static int	ft_working_path_init(t_global *glob)
{
	int		i;

	i = 0;
	if (!(glob->working_path = malloc(sizeof(char *) * glob->nb_room)))
		return (-1);
	while (i < glob->nb_room)
	{
		if (!(glob->working_path[i] = ft_strnew(glob->nb_room)))
			return (-1);
		i++;
	}
	return (1);
}

inline static int	ft_optimize_solution(t_global *glob, t_solution *solution)
{
	int			n_step;

	if ((n_step = ft_calculate_step(glob, glob->n_path + 1, solution)) == -1)
	{
		ft_free_solution(&solution);
		return (1);
	}
	if (glob->n_path == 0 || n_step < glob->solution->n_total_step)
	{
		if (glob->n_path != 0)
			ft_free_solution(&(glob->solution));
		glob->n_path++;
		solution->n_total_step = n_step;
		glob->solution = solution;
		ft_adapt_glob_to_new_solution(glob);
		return (0);
	}
	ft_free_solution(&solution);
	return (1);
}

inline static int	ft_find_solution_for_n_path(t_global *glob,
		t_solution *solution)
{
	int			ret;

	if ((ret = ft_find_path(glob)) == -1)
		return (-1);
	else if (ret == 1)
		return (1);
	else
	{
		if ((ret = ft_get_path(glob, solution)) == -1)
			return (-1);
	}
	return (0);
}

int					ft_find_global_solution(t_global *glob)
{
	t_solution	*solution;
	int			ret;
	int			i;

	if (ft_r_status_init(glob) == -1 || ft_working_path_init(glob) == -1)
		return (-1);
	i = 0;
	while (i <= glob->start->nb_link && i <= glob->end->nb_link)
	{
		if (!(solution = ft_solution_new()))
			return (-1);
		if ((ret = ft_find_solution_for_n_path(glob, solution)) != 0)
			return (ret);
		if (ft_optimize_solution(glob, solution))
			return (0);
		i++;
	}
	return (0);
}
