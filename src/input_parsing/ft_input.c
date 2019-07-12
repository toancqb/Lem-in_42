/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:10:47 by qtran             #+#    #+#             */
/*   Updated: 2019/07/11 14:40:44 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib_lem_in.h"
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

t_input *ft_input_init()
{
  t_input *input;

  if (!(input = (t_input*)malloc(sizeof(t_input))))
    exit(0);
  input->type = -1;
  input->index = 0;
  input->check = 0;
  input->n_read = -1;
  return (input);
}

void ft_fin(ssize_t size, char **line, t_input **input)
{
  if ((*input)->check && line)
    free(*line);
  free(*input);
  if (size == -1)
    perror("Error GNL: ");
}

void ft_check_input(t_global *g)
{
  if (g->nb_ant == -1 || g->start == NULL || g->end == NULL)
    ft_error();

}

int ft_input_parsing(t_global *global, int opt)
{
  ssize_t size;
  char *line;
  t_input *input;

  input = ft_input_init();
  while ((size = get_next_line(STDIN_DEFAULT, &line)) > 0)
  {
    if (!is_comment(line))
    {
      if (!ft_check_format_line(line, input))
        break ;
      else if (is_nb_ant(line) && (!ft_parse_nb_ant(line, global, input)))
        break ;
      else if (is_command(line))
        ft_parse_command(line, input);
      else if (is_room(line)
      && (!(ft_parse_room_tmp(line, global, input))))
        break ;
      else if (is_link(line) && (!ft_parse_link(line, global, input)))
        break ;
    }
    if (!(opt & OPT_S))
      ft_putendl(line);
    free(line);
  }
  ft_parse_room(global);
  ft_fin(size, &line, &input);
  ft_check_input(global);
  return (0);
}
