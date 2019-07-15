/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ant.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:33:06 by qtran             #+#    #+#             */
/*   Updated: 2019/07/15 16:49:12 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib_lem_in.h"
#include <stdlib.h>

t_roomlst		*ft_ant_init(int nb_ant)
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

int				ft_nb_ant_in_end(int *check, int nb_ant)
{
	int	i;
	int	count;

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

void			ft_check_init(int *check, int nb_ant)
{
	int	i;

	check[nb_ant + 1] = 3;
	i = 0;
	while (i <= nb_ant)
	{
		check[i] = 0;
		i++;
	}
}

t_roomlst		*ft_next_ant(t_roomlst *ant)
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

void			ft_free_fin(t_roomlst **ant, int **check)
{
	if (ant)
	{
		ft_roomlst_delall(ant);
		free(*ant);
	}
	if (check)
	{
		free(*check);
	}
}
