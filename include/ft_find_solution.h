/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_solution.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:53:19 by gly               #+#    #+#             */
/*   Updated: 2019/06/27 16:12:40 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FIND_SOLUTION_H
# define FT_FIND_SOLUTION_H

# define VISITED 1
# define ACTIVE 1 << 1
# define ACTIVISIT VISITED + ACTIVE
# define NEGATIVE 1 << 2

typedef struct		s_pathlst
{
	int				n_step;
	t_roomlst		*path;
	struct s_path	*next;
}					t_pathlst;

typedef struct		s_solution
{
	int				n_total_step;
	t_pathlst		*pathlst;
}					t_solution;

int				g_visit_tab[] = {\
	VISIT_ONE, VISIT_TWO, VISIT_THREE, VISIT_FOUR\
};

int				ft_find_global_solution(t_glob *glob);
int				ft_find_path(t_global *glob);
int				ft_get_path(t_global *glob, t_solution *solution);
int				ft_add_path(t_global *glob, t_roomlst *room_path);
int					ft_explore_backward(t_global *glob,
		t_roomlst **room_lst, t_room *room);

int				ft_add_room_to_path(char **working_path, t_room *from, t_room *to,
		int path_flag);

t_pathlst			*ft_pathlst_new(t_roomlst *path, int n_step);
int					ft_pathlst_add(t_pathlst **pathlst, t_pathlst *elem);

t_solution			*ft_solution_new(void);
void				ft_free_solution(t_solution **solution);

//need to be implemented
//#in ft_optimize_solution
//ft_calculate_step
//ft_change_path_matrix
#endif
