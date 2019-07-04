/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_working_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 09:31:58 by gly               #+#    #+#             */
/*   Updated: 2019/07/04 09:37:41 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_find_solution.h"

void	print_working_path(t_global *glob)
{
	int		i;
	int		j;

	i = 0;
	while (i < glob->nb_room)
	{
		j = 0;
		while (j < glob->nb_room)
		{
			printf("%d%d%d, ", glob->working_path[i][j] & NEGATIVE ? -1 : 0,
					glob->working_path[i][j] & ACTIVE ? 1 : 0,
					glob->working_path[i][j] & VISITED ? 1 : 0);
			j++;
		}
		puts("");
		i++;
	}
}
