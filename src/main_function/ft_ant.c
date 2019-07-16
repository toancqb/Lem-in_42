/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ant.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 16:34:21 by gly               #+#    #+#             */
/*   Updated: 2019/07/16 16:40:55 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib_lem_in.h"
#include <stdlib.h>

t_roomlst	*ft_ant_init(int nb_ant)
{
	t_roomlst	*ant;

	if (nb_ant > 0)
	{
		ant = NULL;
		while (nb_ant > 0)
		{
			ft_roomlst_add(&ant, ft_roomlst_new(NULL, nb_ant));
			nb_ant--;
		}
		return (ant);
	}
	return (NULL);
}

int			ft_nb_ant_in_end(int *check, int nb_ant)
{
	int		i;
	int		count;

	i = 1;
	count = 0;
	while (i <= nb_ant)
	{
		if (check[i] == 1)
			count++;
		i++;
	}
	return (count);
}

void		ft_move_current_ant(t_roomlst *ant, t_global *g)
{
	t_roomlst	*tmp;

	tmp = ant;
	while (tmp != NULL)
	{
		if (tmp->r != NULL && tmp->r != g->end)
			tmp->r = tmp->r->p;
		tmp = tmp->next;
	}
}

t_roomlst	*ft_next_ant(t_roomlst *ant)
{
	t_roomlst	*tmp;

	tmp = ant;
	while (tmp != NULL)
	{
		if (tmp->r == NULL)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
