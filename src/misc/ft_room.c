/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_room.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 12:52:52 by qtran             #+#    #+#             */
/*   Updated: 2019/07/16 16:24:35 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib_lem_in.h"
#include <stdlib.h>
#include "libft.h"

t_room	*ft_room_init(void)
{
	t_room	*r;

	if (!(r = (t_room*)malloc(sizeof(t_room))))
		exit(0);
	r->ant_cur = -1;
	r->type = -1;
	r->nb_link = 0;
	r->flag = -1;
	r->name = NULL;
	if (!(r->link = (t_roomlst**)malloc(sizeof(t_roomlst*))))
		exit(0);
	*(r->link) = NULL;
	r->p = NULL;
	return (r);
}

t_room	*ft_room_new(char *name)
{
	t_room	*r;

	r = ft_room_init();
	r->name = ft_strdup(name);
	return (r);
}
