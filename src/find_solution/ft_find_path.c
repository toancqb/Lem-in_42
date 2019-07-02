/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 12:41:42 by gly               #+#    #+#             */
/*   Updated: 2019/07/02 14:04:47 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_find_solution.h"

void	ft_add_room_to_path(t_global *glob,
		t_room *from, t_room *to)
{
	glob->working_path[from->i][to->i] |= VISITED;
	glob->r_status[to->i] |= VISITED;
}

static inline int	ft_explore_next_room(t_global *glob, t_roomlst *next_room,
		t_roomlst **room_lst)
{
	t_roomlst	*elem;

	while (next_room != NULL)
	{
		if (!(glob->r_status[next_room->r->i] & VISITED))
		{
			if (glob->r_status[next_room->r->i] & ACTIVE)
			{
				if (ft_explore_backward(glob, room_lst, next_room->r,
							(*room_lst)->rank + 1))
					return (-1);
			}
			else
			{
				ft_add_room_to_path(glob, (*room_lst)->r, next_room->r);
				if (next_room->r == glob->end)
					return (0);
				else if (!(elem = ft_roomlst_new(next_room->r,
								(*room_lst)->rank == 0 ? 0 : (*room_lst)->rank - 1)))
					return (-1);
				ft_roomlst_add_rank(room_lst, elem);
			}
		}
		next_room = next_room->next;
	}
	return (1);
}

int					ft_find_path(t_global *glob)
{
	t_roomlst	*room_lst;
	int			ret;

	if (!(room_lst = ft_roomlst_new(glob->start, 0)))
		return (-1);
	while (room_lst != NULL)
	{
		if ((ret = ft_explore_next_room(glob,
						*room_lst->r->link, &room_lst)) != 1)
		{
			ft_roomlst_delall(&room_lst);
			return (ret);
		}
		free(ft_roomlst_shift(&room_lst));
	}
	return (0);
}
