/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 12:43:56 by gly               #+#    #+#             */
/*   Updated: 2019/07/09 13:33:41 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_find_solution.h"

static inline t_room	*ft_get_next_room(t_global *glob, t_room *room)
{
	t_roomlst	*link;
	t_room		*tmp;

	link = *(room->link);
	tmp = NULL;
	while (link != NULL)
	{
		if (glob->working_path[link->r->i][room->i] & REV_UP)
			return (link->r);
		else if (glob->working_path[link->r->i][room->i] & ACTIVISIT
				&& !(glob->working_path[link->r->i][room->i] & REV_DOWN))
			tmp = link->r;
		link = link->next;
	}
	return (tmp);
}

static inline int	ft_get_new_path2(t_global *glob, t_room *room,
		t_roomlst **path)
{
	t_room		*next_room;
	t_roomlst	*elem;

	while (room != NULL)
	{
		if (!(next_room = ft_get_next_room(glob, room)))
			return (-1);
		if (!(elem = ft_roomlst_new(next_room, 0)))
			return (-1);
		ft_roomlst_add(path, elem);
		if (next_room == glob->start)
			return (0);
		room = next_room;
	}
	return (1);
}

static inline int	ft_get_new_path(t_global *glob, t_roomlst **path)
{
	t_roomlst	*link;
	t_roomlst	*elem;

	if (!(*path = ft_roomlst_new(glob->end, 0)))
		return (-1);
	link = *(glob->end->link);
	while (link != NULL)
	{
		if (glob->working_path[link->r->i][glob->end->i] & ACTIVISIT
				&& !(glob->r_status[link->r->i] & ACTIVE))
		{
			if (!(elem = ft_roomlst_new(link->r, 0)))
				return (-1);
			ft_roomlst_add(path, elem);
			if (link->r == glob->start)
				return (0);
			return (ft_get_new_path2(glob, link->r, path));
		}
		link = link->next;
	}
	return (1);
}

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
	int		i;
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

int		ft_get_path(t_global *glob, t_solution *solution)
{
	t_roomlst	*new_path;
	int			ret;

	new_path = NULL;
	if ((ret = ft_get_new_path(glob, &new_path)) != 0)
		return (ret);
	if (ft_get_new_solution(glob, new_path, solution) == -1)
		return (-1);
	return (0);
}
