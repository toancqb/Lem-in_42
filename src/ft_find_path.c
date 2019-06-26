/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 12:41:42 by gly               #+#    #+#             */
/*   Updated: 2019/06/25 18:48:32 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_find_solution.h"

int		ft_find_path2(t_global *glob, int path_flag, t_roomlst *new_roomlst,
		t_roomlst *room_lst)
{
	t_roomlst	*elem;

	while (new_roomlst != NULL)
	{
		if (new_roomlst->room->flag & path_flag)
		{
			ft_add_room_to_path(glob->working_path, room_lst->r, new_roomlst->r,
					path_flag);
			if (new_roomlst->r == glob->end)
			{
				ft_roomlst_delall(&room_lst);
				return (0);
			}
			else if (!(elem = ft_lstnew(new_roomlst->r)))
				return (-1);
			ft_lstpush(&room_lst, elem);
		}
		new_roomlst = new_roomlst->next;
	}
	return (1);
}

int		ft_find_path(t_global *glob, int n)
{
	t_roomlst	*room_lst;
	t_roomlst	*new_roomlst;
	t_roomlst	*elem;
	int			ret;

	if (!(room_lst = ft_roomlst_new(glob->start)))
		return (-1);
	while (room_lst != NULL)
	{
		new_roomlst = room_lst->link;
		if ((ret = ft_find_path2(glob, path_flag, new_roomlst, room_lst)) != 1)
			return (ret);
		elem = ft_roomlst_shift(&room_lst);
		free(elem);
	}
	return (1);
}
