/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 11:08:29 by qtran             #+#    #+#             */
/*   Updated: 2019/07/12 16:20:16 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib_lem_in.h"
#include "ft_find_solution.h"
#include <stdlib.h>

t_global *ft_global_init()
{
  t_global *global;

  if (!(global = (t_global*)malloc(sizeof(t_global))))
    exit(0);
  global->start = NULL;
  global->end = NULL;
  global->nb_ant = -1;
  global->nb_room = 0;
  global->n_path = 0;
  global->r_status = NULL;
  global->working_path = NULL;
  if (!(global->r_tmp = (t_roomlst**)malloc(sizeof(t_roomlst*))))
    exit(0);
  *(global->r_tmp) = NULL;
  global->rooms = NULL;
  global->solution = NULL;
  return (global);
}

void ft_room_free(t_room **room)
{
  t_room *r;

  if (room)
  {
    r = *room;
    if (r->name)
      free(r->name);
    ft_roomlst_delall(r->link);
    free(r->link);
    free(*room);
  }
}

void ft_global_free(t_global **global)
{
  int i;
  t_global *g;

  i = 0;
  g = *global;
  if (g->r_status)
    free(g->r_status);
  if (g->solution != NULL)
    ft_free_solution(&(g->solution));
  while (g->rooms[i] != NULL)
  {
    ft_room_free(&(g->rooms[i]));
    i++;
  }
  if (g->working_path)
  {
    i = 0;
    while (g->working_path[i] != NULL)
    {
      free(g->working_path[i]);
      i++;
    }
    free(g->working_path);
  }
  free(g->rooms);
  ft_roomlst_delall(g->r_tmp);
  free(g->r_tmp);
  free(g);
}
