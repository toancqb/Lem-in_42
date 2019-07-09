/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_single_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 11:32:07 by gly               #+#    #+#             */
/*   Updated: 2019/07/09 12:43:09 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_find_solution.h"

static inline t_room	*ft_get_next_room(t_global *glob, t_room *room)
{
	t_roomlst	*link;
	t_room		*tmp;

	link = *(room->link);
	tmp = NULL;
	while (link != NULL)
	{
		if (glob->working_path[link->r->i][room->i] & ACTIVISIT)
		{
			if (glob->r_status[link->r->i] & ACTIVE)
				return (link->r);
			else
				tmp = link->r;
		}
		link = link->next;
	}
	return (tmp);
}		

static inline int	ft_get_single_path2(t_global *glob, t_room *room,
		t_roomlst **path)
{
	t_room	*next_room;
	t_roomlst	*elem;
	int		n_step;

	n_step = 1;
	while (room != NULL)
	{
		if (!(next_room = ft_get_next_room(glob, room)))
			return (-1);
		if (!(elem = ft_roomlst_new(next_room, 0)))
			return (-1);
		ft_roomlst_add(path, elem);
		n_step++;
		if (next_room == glob->start)
			return (n_step);
		ft_bzero(glob->working_path[next_room->i], sizeof(char) * glob->nb_room);
		room = next_room;
	}
	return (-1);
}

int	ft_get_single_path(t_global *glob, t_roomlst **path)
{
	t_roomlst	*link;
	t_roomlst	*elem;

	link = *(glob->end->link);
	while (link != NULL)
	{
		if (glob->working_path[link->r->i][glob->end->i] & ACTIVISIT)
		{
			if (!(elem = ft_roomlst_new(link->r, 0)))
				return (-1);
			ft_roomlst_add(path, elem);
			if (link->r == glob->start)
				return (1);
			ft_bzero(glob->working_path[link->r->i], sizeof(char) * glob->nb_room);
			return (ft_get_single_path2(glob, link->r, path));
		}
		link = link->next;
	}
	return (0);
}
