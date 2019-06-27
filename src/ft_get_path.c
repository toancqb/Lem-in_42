/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:35:14 by gly               #+#    #+#             */
/*   Updated: 2019/06/27 16:09:26 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_find_solution.h"

static inline int	ft_get_single_path2(t_global *glob, int i)
{
	int			n_step;
	int			j;
	t_roomlst	*room;

	j = glob->end->i;
	while (i < glob->nb_rooms)
	{
		if (glob->working_path[i][j] & ACTIVE &&
				!(glob->working_path[i][j] & NEGATIVE))
		{
			n_step++;
			if (!(room = ft_roomlst_new(glob->room[i])))
				return (-1);
			ft_roomlst_shift(path, room);
			j = i;
			i = 0;
			if (j == glob->start->i)
				return (n_step);
		}
		i++;
	}
}

static inline int	ft_get_single_path(t_global *glob, int *i,
		t_roomlst **path)
{
	while (*i < glob->nb_rooms)
	{
		if (glob->working_path[*i][glob->end->i] & ACTIVE &&
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
	while (i < glob->nb_rooms)
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
