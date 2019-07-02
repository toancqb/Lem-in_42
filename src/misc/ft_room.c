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

#include "ft_lib_lem_in.h"
#include <stdlib.h>
#include "libft.h"

t_room *ft_room_init()
{
  t_room *r;

  if (!(r = (t_room*)malloc(sizeof(t_room))))
    exit(0);
  r->ant_cur = -1;
  r->type = -1;
  r->nb_link = -1;
  r->flag = -1;
  r->name = NULL;
  r->link = (t_roomlst**)malloc(sizeof(t_roomlst*));
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
    //if (r->link)
    //  ft_lstdel(r->link, &ft_lstdelone);
    if (r->data)
      free(r->data);
    free(*room);
    *room = NULL;
  }
}
