/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:35:14 by gly               #+#    #+#             */
/*   Updated: 2019/07/02 11:32:27 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_find_solution.h"

static inline int	ft_get_single_path2(t_global *glob, int i, t_roomlst **path)
{
	int			n_step;
	int			j;
	t_roomlst	*room;

	j = glob->end->i;
	n_step = 0;
	while (i < glob->nb_room)
	{
		if (glob->working_path[i][j] & ACTIVISIT &&
				!(glob->working_path[i][j] & NEGATIVE))
		{
			n_step++;
			if (!(room = ft_roomlst_new(glob->rooms[i], 0)))
				return (-1);
			ft_roomlst_add(path, room);
			j = i;
			i = 0;
			if (j == glob->start->i)
				return (n_step);
		}
		i++;
	}
	return (n_step);
}

static inline int	ft_get_single_path(t_global *glob, int *i,
		t_roomlst **path)
{
	while (*i < glob->nb_room)
	{
		if (glob->working_path[*i][glob->end->i] & ACTIVISIT &&
				!(glob->working_path[*i][glob->end->i] & NEGATIVE))
			return (ft_get_single_path2(glob, *i, path));
		(*i)++;
	}
	return (0);
}

int					ft_get_path(t_global *glob, t_solution *solution)
{
	int			i;
	t_pathlst	*pathlst;
	t_roomlst	*path;
	t_pathlst	*elem;
	int			n_step;

	pathlst = NULL;
	path = NULL;
	i = 0;
	while (i < glob->nb_room)
	{
		if ((n_step = ft_get_single_path(glob, &i, &path)) == -1)
			return (-1);
		if (!(elem = ft_pathlst_new(path, n_step)))
			return (-1);
		ft_pathlst_add(&pathlst, elem);
		i++;
	}
	solution->pathlst = pathlst;
	return (0);
}