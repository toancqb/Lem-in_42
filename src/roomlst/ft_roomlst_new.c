/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roomlst_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 09:40:16 by gly               #+#    #+#             */
/*   Updated: 2019/07/16 16:30:11 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_lib_lem_in.h"

t_roomlst	*ft_roomlst_new(t_room *room, int rank)
{
	t_roomlst	*roomlst;

	if (!(roomlst = (t_roomlst*)malloc(sizeof(t_roomlst))))
		return (NULL);
	roomlst->r = room;
	roomlst->rank = rank;
	roomlst->next = NULL;
	return (roomlst);
}
