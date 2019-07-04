/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_solution.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:53:19 by gly               #+#    #+#             */
/*   Updated: 2019/07/02 16:26:29 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FIND_SOLUTION_H
# define FT_FIND_SOLUTION_H

# define VISITED 1
# define ACTIVE 1 << 1
# define ACTIVISIT 3
# define NEGATIVE 1 << 2
#include "ft_lib_lem_in.h"


#include <stdio.h>

int				ft_find_global_solution(t_global *glob);
int				ft_find_path(t_global *glob);
int				ft_get_path(t_global *glob, t_solution *solution);
int					ft_explore_backward(t_global *glob,
		t_roomlst **room_lst, t_room *room, int rank);
int					ft_calculate_step(t_global *glob,
		int n_path, t_solution *solution);

void			ft_add_room_to_path(t_global *glob,
		t_room *from, t_room *to);
void	ft_adapt_glob_to_new_solution(t_global *glob);
t_pathlst			*ft_pathlst_new(t_roomlst *path, int n_step);
int					ft_pathlst_add(t_pathlst **pathlst, t_pathlst *elem);

t_solution			*ft_solution_new(void);
void				ft_free_solution(t_solution **solution);

//need to be implemented
//#in ft_optimize_solution
//ft_calculate_step
//ft_change_path_matrix
#endif
