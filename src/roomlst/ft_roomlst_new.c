/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roomlst_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 09:40:16 by gly               #+#    #+#             */
/*   Updated: 2019/07/02 09:44:36 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_lib_lem_in.h"

t_roomlst *ft_roomlst_new(t_room *room, int rank)
{
  t_roomlst *room;

  if (!(room = malloc(sizeof(t_roomlst))))
    return (NULL);
  room->r = room;
  room->rank = rank;
  room->next = NULL;
  return (room);
}
