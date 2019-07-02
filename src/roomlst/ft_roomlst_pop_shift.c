/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roomlst_pop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:13:47 by qtran             #+#    #+#             */
/*   Updated: 2019/06/25 14:13:48 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_lib_lem_in.h"

t_roomlst *ft_roomlst_shift(t_roomlst **lst)
{
  t_roomlst *shift;

  if (lst)
  {
    shift = *lst;
    *lst = (*lst)->next;
    shift->next = NULL;
    return (shift);
  }
  return (NULL);
}

t_roomlst *ft_roomlst_pop(t_roomlst **lst)
{
  t_roomlst *pop;
  t_roomlst *tmp;

  if (lst)
  {
    if ((*lst)->next == NULL)
    {
      pop = *lst;
      *lst = NULL;
    }
    else
    {
      tmp = *lst;
      pop = tmp->next;
      while (pop->next != NULL)
      {
        pop = pop->next;
        tmp = tmp->next;
      }
      tmp->next = NULL;
    }
    return (pop);
  }
  return (NULL);
}
