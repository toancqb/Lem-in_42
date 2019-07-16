/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:10:47 by qtran             #+#    #+#             */
/*   Updated: 2019/07/16 16:19:09 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib_lem_in.h"
#include <stdlib.h>
#include "libft.h"

int		ft_parse_nb_ant(char *line, t_global *global, t_input *input)
{
	input->n_read += (input->n_read == -1) ? 1 : 0;
	if (input->n_read != 0)
	{
		input->check = 1;
		return (0);
	}
	global->nb_ant = ft_atoi(line);
	return (1);
}

void	ft_parse_command(char *line, t_input *input)
{
	if (!ft_strcmp((const char *)line, "##start"))
		input->type = 1;
	else if (!ft_strcmp((const char *)line, "##end"))
		input->type = 0;
}

int		ft_parse_link(char *line, t_global *global, t_input *input)
{
	t_room	*r1;
	t_room	*r2;

	input->n_read += (input->n_read == 1) ? 1 : 0;
	if (input->n_read != 2)
	{
		input->check = 1;
		return (0);
	}
	r1 = ft_get_room_by_line(global, line, 0);
	r2 = ft_get_room_by_line(global, line, 1);
	if (r1 == NULL || r2 == NULL)
	{
		input->check = 1;
		return (0);
	}
	(r1->nb_link)++;
	ft_roomlst_add(r1->link, ft_roomlst_init(r2));
	(r2->nb_link)++;
	ft_roomlst_add(r2->link, ft_roomlst_init(r1));
	return (1);
}

void	ft_parse_room(t_global *global)
{
	int			len;
	int			i;
	t_roomlst	*tmp;

	len = ft_roomlst_len(*(global->r_tmp));
	if (!(global->rooms = (t_room**)malloc(sizeof(t_room*) * (len + 1))))
		exit(0);
	global->rooms[len] = NULL;
	i = 0;
	while (i < len)
	{
		tmp = ft_roomlst_shift(global->r_tmp);
		global->rooms[i] = tmp->r;
		tmp->r = NULL;
		free(tmp);
		i++;
	}
}
