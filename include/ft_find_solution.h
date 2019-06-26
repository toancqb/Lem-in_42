/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_solution.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:53:19 by gly               #+#    #+#             */
/*   Updated: 2019/06/25 18:57:35 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FIND_SOLUTION_H
# define FT_FIND_SOLUTION_H

# define VISIT_ONE 1
# define VISIT_TWO	1 << 1
# define VISIT_THREE 1 << 2
# define VISIT_FOUR 1 << 3
# define NEGATIVE 1 << 4

# define ACTIVE VISIT_ONE + VISIT_TWO + VISIT_THREE + VISIT_FOUR

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

int				ft_find_solution(t_glob *glob);
int				ft_find_path(t_global *glob, int path_flag);
int				ft_get_path(t_global *glob, t_roomlst **room_path);
int				ft_add_path(t_global *glob, t_roomlst **room_path);
int				ft_add_room_to_path(char **working_path, t_room *from, t_room *to,
		int path_flag);


//need to be implemented
//#in ft_optimize_solution
//ft_calculate_step
//ft_free_solution
//ft_change_path_matrix
#endif
