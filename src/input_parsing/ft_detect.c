/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:16:13 by qtran             #+#    #+#             */
/*   Updated: 2019/07/02 16:03:20 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib_lem_in.h"
#include "libft.h"

int is_command(char *line)
{
  if (line == NULL)
    return (-1);
  if (line[0] == '#' && line[1] == '#')
    return (1);
  return (0);
}

int is_comment(char *line)
{
  if (line == NULL)
    return (-1);
  if (line[0] == '#' && line[1] != '#')
    return (1);
  return (0);
}

int is_nb_ant(char *line)
{
  int i;

  i = 0;
  if (line == NULL)
    return (-1);
  if (line[0] == '\0')
    return (0);
  while (line[i] != '\0')
  {
    if (line[i] < '0' || line[i] > '9')
      return (0);
    i++;
  }
  if (!is_in_intmax(line, ft_strlen(line))) // need to implement
    ft_error();
  return (1);
}

int is_room_simple(char *line)
{
  int i;
  int count;

  i = 0;
  count = 0;
  if (line == NULL)
    return (-1);
  if (line[0] == 'L')
    return (0);
  while (line[i] != '\0' && line[i] != ' ')
    i++;
  while (line[i] != '\0')
  {
    if (line[i] == ' ')
      count++;
    i++;
  }
  return ((count == 2)? 1 : 0);
}

int is_room(char *line)
{
  int i;
  char *tmp;

  if (is_room_simple(line) == 0)
    return (0);
  while (*line != '\0' && *line != ' ')
    line++;
  tmp = ++line;
  while (*tmp != '\0' && *tmp != ' ')
    tmp++;
  if (!is_in_intmax(line, (int)(tmp - line))) // need to implement
    return (0);
  line = ++tmp;
  while (*tmp != '\0')
    tmp++;
  if (!is_in_intmax(line, (int)(tmp - line))) // need to implement
    return (0);
}

int is_link(char *line)
{
  if (line == NULL)
    return (-1);
  if (ft_strchr(line, '-'))
    return (1);
  return (0);
}
