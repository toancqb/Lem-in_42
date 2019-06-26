/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_room_to_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:49:00 by gly               #+#    #+#             */
/*   Updated: 2019/06/25 16:35:26 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_find_solution.h"

int		ft_add_room_to_path(char **working_path, t_room *from, t_room *to,
		int path_flag)
{
	working_path[from->i][to->i] |= ACTIVE;
	to->flag |= path_flag;
}
