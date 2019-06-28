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
  r->nb_link = -1;
  r->flag = -1;
  r->name = NULL;
  r->link = (t_list**)malloc(sizeof(t_list*));
  *(r->link) = NULL;
  r->data = NULL;
  return (r);
}

t_room *ft_room_new(char *name)
{
	t_room *r;

	r = ft_room_init();
	r->name = ft_strdup(name);
	return (r);
}

void ft_room_free(t_room **room)
{
  t_room *r;

  if (room)
  {
    r = *room;
    if (r->name)
      free(r->name);
    //if (r->links)
    //  ft_lstdel(&(r->links), &ft_lstdelone);
    if (r->data)
      free(r->data);
    free(*room);
    *room = NULL;
  }
}
