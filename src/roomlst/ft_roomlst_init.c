/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roomlst_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:13:33 by qtran             #+#    #+#             */
/*   Updated: 2019/06/25 14:13:34 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_lib_lem_in.h"

t_roomlst *ft_roomlst_init(t_room *room)
{
  t_roomlst *r;

  if (!(r = (t_roomlst*)malloc(sizeof(t_roomlst))))
    exit(0);
  r->r = room;
  r->next = NULL;
  return (r);
}
