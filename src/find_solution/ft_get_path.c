/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 12:43:56 by gly               #+#    #+#             */
/*   Updated: 2019/07/09 14:34:06 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_find_solution.h"

static inline int	ft_trace_path(t_global *glob, t_roomlst *path)
{
	if (path == NULL)
		return (-1);
	while (path->r != glob->end)
	{
		if (glob->working_path[path->next->r->i][path->r->i] & ACTIVE)
			glob->working_path[path->next->r->i][path->r->i] = 0;
		else
			glob->working_path[path->r->i][path->next->r->i] = ACTIVISIT;
		path = path->next;
	}
	return (0);
}

static inline int	ft_get_new_solution(t_global *glob, t_roomlst *new_path,
		t_solution *solution)
{
	int			i;
	t_roomlst	*path;
	t_pathlst	*elem;
	int			n_step;

	i = 0;
	if (glob->n_path != 0)
		ft_adapt_glob_to_new_solution(glob);
	ft_trace_path(glob, new_path);
	while (i <= glob->n_path)
	{
		if (!(path = ft_roomlst_new(glob->end, 0)))
			return (-1);
		if ((n_step = ft_get_single_path(glob, &path)) <= 0)
			return (-1);
		if (!(elem = ft_pathlst_new(path, n_step)))
			return (-1);
		ft_pathlst_add(&(solution->pathlst), elem);
		i++;
	}
	return (0);
}

int					ft_get_path(t_global *glob, t_solution *solution)
{
	t_roomlst	*new_path;
	int			ret;

	new_path = NULL;
	if ((ret = ft_get_new_path(glob, &new_path)) != 0)
		return (ret);
	if (ft_get_new_solution(glob, new_path, solution) == -1)
		return (-1);
	ft_roomlst_delall(&new_path);
	return (0);
}
