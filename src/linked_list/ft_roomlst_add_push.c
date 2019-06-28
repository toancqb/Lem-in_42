/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roomlst_add_push.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:13:40 by qtran             #+#    #+#             */
/*   Updated: 2019/06/25 14:13:41 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_lib_lem_in.h"

void ft_roomlst_add(t_roomlst **lst, t_roomlst *elem)
{
  if (lst)
  {
    if (*lst == NULL)
      *lst = elem;
    else
    {
      elem->next = *lst;
      *lst = elem;
    }
  }
}

void ft_roomlst_add_second(t_roomlst **lst, t_roomlst *elem)
{
  if (lst)
  {
    if (*lst == NULL)
      *lst = elem;
    else
    {
      elem->next = (*lst)->next;
      (*lst)->next = elem;
    }
  }
}

void ft_roomlst_push(t_roomlst **lst, t_roomlst *elem)
{
  t_roomlst *tmp;

  if (lst)
  {
    if (*lst == NULL)
      *lst = elem;
    else
    {
      tmp = *lst;
      while (tmp->next != NULL)
        tmp = tmp->next;
      tmp->next = elem;
    }
  }
}