/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_room.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 12:52:52 by qtran             #+#    #+#             */
/*   Updated: 2019/06/25 12:52:53 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_lib_lem_in.h"

t_room *ft_room_init()
{
  t_room *r;

  r = (t_room*)malloc(sizeof(t_room));
  r->ant_cur = -1;
  r->type = -1;
  r->nb_links = -1;
  r->flag = -1;
  r->name = NULL;
  r->links = NULL;
  r->data = NULL;
  return (r);
}
