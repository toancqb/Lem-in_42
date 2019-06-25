/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roomlst_add_del.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:34:34 by qtran             #+#    #+#             */
/*   Updated: 2019/06/25 13:34:35 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lem_in_lib.h"

void ft_roomlst_add_node(t_roomlst **node_master, t_roomlst *node)
{
  t_roomlst *n_cpy;
  t_roomlst *tmp;

  n_cpy = ft_roomlst_cpy_node(node);
  tmp = *node_master;
  while (tmp->next != NULL)
  {
    tmp = tmp->next;
  }
  tmp->next = n_cpy;
}

void ft_roomlst_mem_add(t_roomlst **master, t_roomlst *node)
{
  t_roomlst *tmp;

  if (*master == NULL)
    *master = ft_roomlst_cpy_node(node);
  else
  {
    tmp = *master;
    while (tmp->next != NULL)
      tmp = tmp->next;
    tmp->next = ft_roomlst_cpy_node(node);
  }
}

int ft_roomlst_mem_len(t_roomlst *master)
{
  int len;
  t_roomlst *tmp;

  len = 0;
  tmp = master;
  if (tmp == NULL)
    return (len);
  while (tmp != NULL)
  {
    len++;
    tmp = tmp->next;
  }
  return (len);
}

void ft_roomlst_mem_del(t_roomlst **master, char *name)
{
  t_roomlst *tmp;
  t_roomlst *tmp_name;

  tmp = *master;
  if (ft_roomlst_mem_len(tmp) == 0)
    return ;
  if (ft_roomlst_mem_len(tmp) == 1 && ft_strequ(tmp->r->name, name))
  {
    ft_roomlst_mem_free_one_node(&tmp);
    return ;
  }
  if (ft_strequ(tmp->r->name, name))
  {
    tmp_name = tmp->next;
    ft_roomlst_mem_free_one_node(&tmp);
    *master = tmp_name;
    return ;
  }
  tmp_name = tmp->next;
  while (tmp_name != NULL)
  {
    if (ft_strequ(tmp_name->r->name, name))
    {
      tmp->next = tmp_name->next;
      ft_roomlst_mem_free_one_node(&tmp_name);
      break ;
    }
    tmp_name = tmp_name->next;
    tmp = tmp->next;
  }
}

void ft_roomlst_mem_func(t_roomlst *master, void (*f)(t_roomlst *mem))
{
  t_roomlst *tmp;

  tmp = master;
  while (tmp != NULL)
  {
    f(tmp);
    tmp = tmp->next;
  }
  ft_putstr("\n");
}
