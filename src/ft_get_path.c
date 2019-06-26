/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:35:14 by gly               #+#    #+#             */
/*   Updated: 2019/06/25 18:58:43 by gly              ###   ########.fr       */
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
			!glob->working_path[i][j] & NEGATIVE))
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

static inline int	ft_get_single_path(t_global *glob, int 	*i,
	t_roomlst **path)
{
	while (*i < glob->nb_rooms)
	{
		if (glob->working_path[*i][glob->end->i] & ACTIVE &&
			!glob->working_path[*i][glob->end->i] & NEGATIVE))
			return (ft_get_single_path2(glob, *i, path));
		(*i)++;			
	}
	return (0);
}

int		ft_get_path(t_global *glob, t_solution *solution, int n_path)
{
	int			i;
	t_pathlst	*pathlst;
	t_roomlst	*path;
	int			n_step;

	if (!(pathlst = malloc(sizeof(t_pathlst))))
		return (-1);
	ft_bzero(pathlst, sizeof(t_pathlst));
	path = NULL;
	i = 0;
	while (n_path > 0)
	{
		if ((n_step = ft_get_single_path(glob, &i, &path)) == -1)
			return (-1);
		ft_pathlst_add(pathlst, path, n_step);
		n_path--;	
		i++;	
	}
	return (0);
}