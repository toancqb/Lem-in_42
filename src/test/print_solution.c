#include "ft_printf.h"
#include "ft_find_solution.h"

void	print_rooms(t_global *glob)
{
	int		i;

	i = 0;
	while (i < glob->nb_room)
	{
		printf("Room %02d is %s.\n", i, glob->rooms[i]->name);
		i++;
	}
}

void	print_pathlst(t_pathlst *pathlst)
{
	t_roomlst *path;

	while (pathlst != NULL)
	{
		path = pathlst->path;
		printf("The path length is %d.\n", pathlst->n_step);
		ft_roomlst_iter(path, &f_print_roomlst);
		puts("");
		pathlst = pathlst->next;
	}
}

void	print_rstatus(t_global *glob)
{
	int		i;

	i = 0;
	while (i < glob->nb_room)
	{
		printf("%d%d%d,", glob->r_status[i] & NEGATIVE ? -1 : 0,
				glob->r_status[i] & ACTIVE ? 1 : 0,
				glob->r_status[i] & VISITED ? 1 : 0);
		i++;
	}
	puts("");
}

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
		ft_printf("The number of ant in the path is %d.\n", pathlst->nb_ant);
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
