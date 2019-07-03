/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roomlst_del.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:13:57 by qtran             #+#    #+#             */
/*   Updated: 2019/06/25 14:13:58 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib_lem_in.h"
#include <stdlib.h>

void ft_roomlst_delall(t_roomlst **lst)
{
  t_roomlst *tmp;

  if (lst)
  {
    while (*lst != NULL)
    {
      tmp = *lst;
      *lst = (*lst)->next;
      ft_room_free(&(tmp->r));
      //on ne veut pas free les rooms ici. On veut juste free la roomlst.
      tmp->next = NULL;
      free(tmp);
    }
  }
}