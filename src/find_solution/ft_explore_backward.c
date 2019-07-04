/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_explore_backward.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 11:33:55 by gly               #+#    #+#             */
/*   Updated: 2019/07/04 14:02:05 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_find_solution.h"

static inline void	ft_add_inverse_flow(t_global *glob,
		t_room *from, t_room *to)
{
	glob->working_path[from->i][to->i] |= NEGATIVE;
	glob->r_status[from->i] |= VISITED;
}
static inline t_room	*ft_get_from_room(t_global *glob, int j)
{
	int		i;

	i = 0;
	while (i < glob->nb_room)
	{
		if (glob->working_path[i][j] & ACTIVISIT)
			return (glob->rooms[i]);
		i++;
	}
	return (NULL);
}

int					ft_explore_backward(t_global *glob,
		t_roomlst **room_lst, t_room *room, int rank)
{
	t_roomlst	*next_room;
	t_roomlst	*elem;
	t_room		*from;

	from = ft_get_from_room(glob, room->i);
	if (glob->r_status[from->i] & VISITED || from == glob->start)
		return (0);
	ft_add_room_to_path(glob, (*room_lst)->r, room);
	ft_add_inverse_flow(glob, from, room);
	next_room = *from->link;
	while (next_room != NULL)
	{
		if (!(glob->r_status[next_room->r->i] & ACTIVE) &&
				!(glob->r_status[next_room->r->i] & VISITED))
		{
			ft_add_room_to_path(glob, from, next_room->r);
			if (!(elem = ft_roomlst_new(next_room->r, rank)))
				return (-1);
			ft_roomlst_add_rank(room_lst, elem);
		}
		next_room = next_room->next;
	}
	return (ft_explore_backward(glob, room_lst, from, rank + 1));
}
