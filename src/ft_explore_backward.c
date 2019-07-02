/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_explore_backward.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 11:33:55 by gly               #+#    #+#             */
/*   Updated: 2019/07/02 09:20:06 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_find_solution.h"

static inline void	ft_add_inverse_flow(t_global *glob,
		t_room *from, t_room *to, int rank)
{
	glob->working_path[from->i][to->i] |= NEGATIVE;
	glob->r_status[from->i] |= VISITED;
}

int					ft_explore_backward(t_global *glob,
		t_roomlst **room_lst, t_room *room, int rank)
{
	t_roomlst	*next_room;
	t_roomlst	*elem;
	int			ret;

	if (glob->r_status[room->from->i] & VISITED || room->from == glob->start)
		return (0);
	ft_add_inverse_flow(glob, room, room->from);
	next_room = room->from->links;
	while (next_room != NULL)
	{
		if (!(glob->r_status[next_room->r->i] & ACTIVE) &&
				!(glob->r_status[next_room->r->i] & VISITED))
		{
			ft_add_room_to_path(glob, room->from, next_room->r);
			if (!(elem = ft_roomlst_new(next_room, rank)))
				return (-1);
			ft_roomlst_add_rank(room_lst, elem);
		}
		next_room = next_room->next;
	}
	return (ft_explore_backward(glob, room_lst, from, rank + 1));
}
