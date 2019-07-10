/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_new_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 14:31:09 by gly               #+#    #+#             */
/*   Updated: 2019/07/09 14:33:50 by gly              ###   ########.fr       */
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

static inline int		ft_get_new_path2(t_global *glob, t_room *room,
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

int						ft_get_new_path(t_global *glob, t_roomlst **path)
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
