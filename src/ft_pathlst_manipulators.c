/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathlst_manipulators.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 09:41:51 by gly               #+#    #+#             */
/*   Updated: 2019/06/27 17:37:12 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_find_solution.h"

t_pathlst	*ft_pathlst_new(t_roomlst *path, int n_step)
{
	t_pathlst	new;

	if (!(new = malloc(sizeof(t_pathlst))))
		return (NULL);
	new->path = path;
	new->n_step = n_step;
	new->next = NULL;
	return (new);
}

int			ft_pathlst_add(t_pathlst **pathlst, t_pathlst *elem)
{
	if (pathlst == NULL)
		return (1);
	if (*pathlst == NULL)
		*pathlst = elem;
	else
	{
		elem->next = *pathlst;
		*pathlst = elem;
	}
	return (0);
}
