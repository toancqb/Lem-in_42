/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roomlst_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:31:43 by qtran             #+#    #+#             */
/*   Updated: 2019/06/25 14:31:44 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_lib_lem_in.h"

int ft_roomlst_len(t_roomlst *lst)
{
  int len;

  len = 0;
  while (*lst != NULL)
  {
    len++;
    *lst = (*lst)->next;
  }
  return (len);
}
