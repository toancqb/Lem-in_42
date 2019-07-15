/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roomlst_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:31:43 by qtran             #+#    #+#             */
/*   Updated: 2019/07/15 16:31:16 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib_lem_in.h"
#include "libft.h"

int		ft_roomlst_len(t_roomlst *lst)
{
	int	len;

	len = 0;
	while (lst != NULL)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

void	ft_roomlst_iter(t_roomlst *lst, void (*f)(t_roomlst *r))
{
	if (lst)
	{
		while (lst != NULL)
		{
			f(lst);
			lst = lst->next;
		}
	}
}
