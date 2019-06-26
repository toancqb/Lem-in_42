/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:21:39 by gly               #+#    #+#             */
/*   Updated: 2019/06/25 15:39:11 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_add_path(t_global *glob, t_roomlst *room_path)
{
	t_roomlst	*elem;
	t_roomlst	*next;

	if (room_path == NULL || (next = room_path->next) == NULL)
		return (-1);
	elem = room_path;
	while (next != NULL)
	{
		glob->path[elem->r->i][next->r->i] |= ACTIVE;
		elem = next;
		next = next->next;
	}
	return (1);
}
