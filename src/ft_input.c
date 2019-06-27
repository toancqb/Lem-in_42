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
        ft_parse_room(line, global, &type, &index);
      if (is_link(line))
        ft_parse_link(line, global);
    }
    free(line);
  }
  if (size == -1)
    perror("Error: ");
  return (0);
}
