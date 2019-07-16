/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_room_tmp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 16:18:53 by gly               #+#    #+#             */
/*   Updated: 2019/07/16 16:22:08 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib_lem_in.h"
#include <stdlib.h>

static inline char	*ft_parse_room_tmp2(t_input *input, char *line,
		t_global *global)
{
	char	*tmp;

	input->n_read += (input->n_read == 0) ? 1 : 0;
	if (input->n_read != 1)
	{
		input->check = 1;
		return (NULL);
	}
	tmp = ft_get_name(line);
	if (!ft_is_double_room(global, tmp))
	{
		input->check = 1;
		free(tmp);
		return (NULL);
	}
	return (tmp);
}

int					ft_parse_room_tmp(char *line, t_global *global,
	t_input *input)
{
	t_room		*r;
	t_roomlst	*rlst;
	char		*tmp;

	if ((tmp = ft_parse_room_tmp2(input, line, global)) == NULL)
		return (0);
	r = ft_room_new(tmp);
	free(tmp);
	r->i = (input->index)++;
	(global->nb_room)++;
	r->ant_cur = -1;
	r->type = input->type;
	if (input->type == 0)
		global->end = r;
	else if (input->type == 1)
		global->start = r;
	input->type = -1;
	rlst = ft_roomlst_init(r);
	ft_roomlst_push(global->r_tmp, rlst);
	return (1);
}
