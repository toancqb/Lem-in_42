/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adapt_glob_to_new_solution.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 17:42:31 by gly               #+#    #+#             */
/*   Updated: 2019/06/27 18:27:58 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static inline void	ft_reset_path_matrix(t_global *glob)
{
	int		n;

	n = 0;
	while (n < glob->nb_rooms)
	{
		ft_bzero(glob->working_path[n], sizeof(char) * glob->nb_rooms);
		n++;
	}
}

void				ft_adapt_glob_to_new_solution(t_global *glob)
{
	t_pathlst	*pathlst;
	t_roomlst	*room;

	ft_bzero(glob->r_status, sizeof(char) * glob->nb_rooms);
	ft_reset_path_matrix(glob);
	pathlst = glob->solution->pathlst;
	while (pathlst != NULL)
	{
		room = pathlst->path;
		glob->r_status[room->r->i] |= VISITED;
		glob->working_path[room->r->i][room->next->r->i] |= ACTIVISIT;
		room = room->next;
		while (room->r != glob->end)
		{
			glob->r_status[room->r->i] |= ACTIVE;
			glob->working_path[room->r->i][room->next->r->i] |= ACTIVISIT;
			room = room->next;
		}
		pathlst = pathlst->next;
	}
}