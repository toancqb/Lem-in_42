/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:16:13 by qtran             #+#    #+#             */
/*   Updated: 2019/06/25 13:16:14 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib_lem_in.h"
#include "libft.h"

int is_command(char *line)
{
  if (line == NULL)
    return (-1);
  if (ft_strstr((const char*)line, "##") != NULL
    && line[0] != '\0' && line[0] == '#' && line[1] == '#')
    return (1);
  return (0);
}

int is_comment(char *line)
{
  if (line == NULL)
    return (-1);
  if (!is_command(line) && line[0] != '\0' && line[0] == '#')
    return (1);
  return (0);
}

int is_nb_ant(char *line)
{
  int i;

  i = 0;
  if (line == NULL)
    return (-1);
  while (line[i] != '\0')
  {
    if (line[i] < '0' || line[i] > '9')
      return (0);
    i++;
  }
  return (1);
}

int is_room(char *line)
{
  int i;
  int count;

  i = 0;
  count = 0;
  if (line == NULL)
    return (-1);
  while (line[i] != '\0' && line[i] != ' ')
    i++;
  while (line[i] != '\0')
  {
    if (line[i] == ' ')
      count++;
    else if (line[i] < '0' || line[i] > '9')
      return (0);
    i++;
  }
  return ((count == 2)? 1 : 0);
}

int is_link(char *line)
{
  if (line == NULL)
    return (-1);
  if (ft_strchr(line, '-'))
    return (1);
  return (0);
}
