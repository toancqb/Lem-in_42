/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:35:14 by gly               #+#    #+#             */
/*   Updated: 2019/07/04 16:49:44 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_find_solution.h"

static inline int	ft_get_single_path2(t_global *glob, int j, t_roomlst **path)
{
	int			n_step;
	int			i;
	t_roomlst	*room;

	n_step = 1;
	i = 0;
	puts("In here");
	while (i < glob->nb_room)
	{
		if (glob->working_path[i][j] & ACTIVISIT
				&& !(glob->working_path[i][j] & NEGATIVE))
		{
			printf("Found a path between %s and %s.\n", glob->rooms[i]->name, glob->rooms[j]->name);
			n_step++;
			if (!(room = ft_roomlst_new(glob->rooms[i], 0)))
				return (-1);
			ft_roomlst_add(path, room);
			if (i == glob->start->i)
				return (n_step);
			ft_bzero(glob->working_path[i], sizeof(char) * glob->nb_room);
			j = i;
			i = 0;
		}
		else
			i++;
	}
	return (n_step);
}

static inline int	ft_get_single_path(t_global *glob, int *i,
		t_roomlst **path)
{
	t_roomlst	*room;

	while (*i < glob->nb_room)
	{
		if (glob->working_path[*i][glob->end->i] & ACTIVISIT)
		{
			if(!(room = ft_roomlst_new(glob->rooms[*i], 0)))
				return (-1);
			ft_roomlst_add(path, room);
			if (*i == glob->start->i)
				return (1);
			return (ft_get_single_path2(glob, *i, path));
		}
		(*i)++;
	}
	return (0);
}

static inline int	ft_get_newest_path(t_global *glob, t_roomlst **path)
{
	int		i;
	t_roomlst	*room;

	i = 0;
	while (i < glob->nb_room)
	{
		if (glob->working_path[i][glob->end->i] & ACTIVISIT
				&& !(glob->r_status[i] & ACTIVE))
		{
			printf("The new path is starting in room %s at index %d.\n", glob->rooms[i]->name, i);
			if (!(room = ft_roomlst_new(glob->rooms[i], 0)))
				return (-1);
			ft_roomlst_add(path, room);
			if (i == glob->start->i)
				return (1);
			ft_bzero(glob->working_path[i], sizeof(char) * glob->nb_room);
			return(ft_get_single_path2(glob, i, path));
		}
		i++;
	}
	return (0);
}

int					ft_get_path(t_global *glob, t_solution *solution)
{
	int			i;
	t_roomlst	*path;
	t_pathlst	*elem;
	int			n_step;

	if (!(path = ft_roomlst_new(glob->end, 0)))
		return (-1);
	if ((n_step = ft_get_newest_path(glob, &path)) <= 0)
		return (n_step);
	if (!(elem = ft_pathlst_new (path, n_step)))
		return (-1);
	ft_pathlst_add(&(solution->pathlst), elem);
	i = 0;
	while (i < glob->nb_room)
	{
		if (!(path = ft_roomlst_new(glob->end, 0)))
			return (-1);
		if ((n_step = ft_get_single_path(glob, &i, &path)) <= 0)
			return (n_step);
		if (!(elem = ft_pathlst_new(path, n_step)))
			return (-1);
		ft_pathlst_add(&(solution->pathlst), elem);
		i++;

	}
	return (0);
}
