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
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

t_global *ft_global_init()
{
  t_global *global;

  if (!(global = (t_global*)malloc(sizeof(t_global))))
    exit(0);
  global->start = NULL;
  global->end = NULL;
  global->nb_ant = 0;
  global->nb_room = 0;
  global->working_path = NULL;
  if (!(global->r_tmp = (t_roomlst**)malloc(sizeof(t_roomlst*))))
    exit(0);
  *(global->r_tmp) = NULL;
  global->rooms = NULL;
  global->solution = NULL;
  return (global);
}

int ft_input_parsing(t_global *global)
{
  ssize_t size;
  char *line;
  int type;
  int index;


  type = -1;
  index = 0;
  while ((size = get_next_line(STDIN_DEFAULT, &line)) > 0)
  {
    ft_putstr(line);
    ft_putchar('\n');
    if (!is_comment(line))
    {
      if (is_nb_ant(line))
        ft_parse_nb_ant(line, global);
      if (is_command(line))
        ft_parse_command(line, &type);
      if (is_room(line))
        ft_parse_room_tmp(line, global, &type, &index);
      if (is_link(line))
        ft_parse_link(line, global);
    }
    free(line);
  }
  ft_parse_room(global);
  if (size == -1)
    perror("Error: ");
  return (0);
}
