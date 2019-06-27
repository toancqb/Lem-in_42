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

#include "../include/ft_lib_lem_in.h"

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
void ft_parse_room(char *line, t_global *global, int *type, int *index)
{
  t_room *r;
  t_roomlst *rlst;

  r = ft_room_new(ft_get_name(line));
  r->i = ((ssize_t)(*index))++;
  r->ant_cur = -1;
  r->type = *type; // type = 0 -> end || = 1 -> start || = -1 -> mid
  if (*type == 0)
    global->end = r;
  else if (*type == 1)
    global->start = r;
  *type = -1;
  rlst = ft_roomlst_init(r);
  ft_roomlst_push(global->rooms, rlst);
}

void ft_parse_link(char *line, t_global *global)
{
  
}
