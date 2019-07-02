#include "ft_printf.h"
#include "ft_lib_lem_in.h"

void	print_solution(t_global *glob)
{
	t_solution	*solution;
	t_pathlst	*pathlst;
	t_roomlst	*path;
	int			i;
	int			j;

	solution = glob->solution;
	pathlst = solution->pathlst;
	i = 0;
	ft_printf("The total number of steps is %d\n", solution->n_total_step);
	while (pathlst != NULL)
	{
		ft_printf("Path %d:\n", i);
		path = pathlst->path;
		j = 0;
		while (path != NULL)
		{
			ft_printf("Room %d: %s\n", j, path->r->name);
			path = path->next;
			j++;
		}
		i++;
		pathlst = pathlst->next;
	}
}	
