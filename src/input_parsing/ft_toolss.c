/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toolss.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 11:10:00 by qtran             #+#    #+#             */
/*   Updated: 2019/07/16 16:10:43 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib_lem_in.h"
#include "libft.h"
#include <stdlib.h>

int			ft_is_double_room(t_global *g, char *tmp)
{
	t_roomlst *rlst;

	rlst = *(g->r_tmp);
	while (rlst != NULL)
	{
		if (!(ft_strcmp(rlst->r->name, tmp)))
			return (0);
		rlst = rlst->next;
	}
	return (1);
}

int			is_in_intmax(const char *str)
{
	int			i;
	long long	nb;
	int			sign;

	i = 0;
	nb = 0;
	sign = str[i] == '-' ? -1 : 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		nb *= 10;
		nb += str[i] - 48;
		if (nb > INT_MAX || nb < INT_MIN)
			return (0);
		i++;
	}
	nb *= sign;
	return (1);
}

static int	ft_is_empty_line(char *line, t_input *input)
{
	if (line && line[0] == '\0')
	{
		input->check = 1;
		return (1);
	}
	return (0);
}

int			ft_check_format_line(char *line, t_input *input)
{
	int		c;

	if (ft_is_empty_line(line, input) == 1)
		return (0);
	if ((c = is_nb_ant(line)) == -1)
	{
		input->check = 1;
		return (-1);
	}
	else if (c)
		return (1);
	if (is_command(line))
		return (2);
	c = is_room(line);
	if (c == -1)
	{
		input->check = 1;
		return (-1);
	}
	else if (is_room(line))
		return (3);
	if (is_link(line))
		return (4);
	input->check = 1;
	return (0);
}
