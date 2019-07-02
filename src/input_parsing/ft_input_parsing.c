/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:10:47 by qtran             #+#    #+#             */
/*   Updated: 2019/06/25 13:10:48 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib_lem_in.h"
#include <stdlib.h>
#include "libft.h"

void ft_parse_nb_ant(char *line, t_global *global)
{
  global->nb_ant = ft_atoi(line);
}

void ft_parse_command(char *line, int *type)
{
  if (ft_strstr((const char*)line, "start") != NULL)
    *type = 1;
  else if (ft_strstr((const char*)line, "end") != NULL)
    *type = 0;
}
void ft_parse_room_tmp(char *line, t_global *global, int *type, int *index)
{
  t_room *r;
  t_roomlst *rlst;
  char *tmp;

  tmp = ft_get_name(line);
  r = ft_room_new(tmp);
  free(tmp);
  r->i = (*index)++;
  (global->nb_room)++;
  r->ant_cur = -1;
  r->type = *type; // type = 0 -> end || = 1 -> start || = -1 -> mid
  if (*type == 0)
    global->end = r;
  else if (*type == 1)
    global->start = r;
  *type = -1;
  rlst = ft_roomlst_init(r);
  ft_roomlst_push(global->r_tmp, rlst);
}

void ft_parse_link(char *line, t_global *global)
{
  t_room *r1;
  t_room *r2;

  r1 = ft_get_room_by_line(global, line, 0);
  r2 = ft_get_room_by_line(global, line, 1);
  (r1->nb_link)++;
  ft_roomlst_add(r1->link, ft_roomlst_init(r2));
  (r2->nb_link)++;
  ft_roomlst_add(r2->link, ft_roomlst_init(r1));
}

void ft_parse_room(t_global *global)
{
  int len;
  int i;
  t_roomlst *tmp;

  len = ft_roomlst_len(*(global->r_tmp));
  if (!(global->rooms = (t_room**)malloc(sizeof(t_room*) * (len + 1))))
    exit(0);
  global->rooms[len] = NULL;
  i = 0;
  while (i < len)
  {
    global->rooms[i] = (t_room*)malloc(sizeof(t_room));
    tmp = ft_roomlst_shift(global->r_tmp);
    global->rooms[i] = tmp->r;
    tmp->r = NULL;
    free(tmp);
    i++;
  }
}
