/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roomlst_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:30:52 by qtran             #+#    #+#             */
/*   Updated: 2019/06/25 13:30:53 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lem_in_lib.h"

t_roomlst *ft_roomlst_init_node()
{
  t_roomlst *node;

  node = (t_roomlst*)malloc(sizeof(t_roomlst));
  node->r = ft_init_room();
  node->next = NULL;
  return (node);
}

t_roomlst *ft_roomlst_cpy_node(t_roomlst *node_org)
{
  t_room *node;
  t_roomlst *n_cpy;

  node = node_org->r;
  n_cpy = ft_roomlst_init_node();
  if (node->name == NULL)
    n_cpy->r->name = NULL;
  else
    n_cpy->r->name = ft_strdup(node->name);
  n_cpy->r->type = node->type;
  n_cpy->r->len_in = node->len_in;
  n_cpy->r->len_out = node->len_out;
  return (n_cpy);
}

void ft_fprint(t_roomlst *node)
{
  if (node == NULL)
  {
    ft_putstr("NULL\n");
    return ;
  }
  ft_putstr("[");
  ft_putstr(node->r->name);
  ft_putstr("]->");
}
