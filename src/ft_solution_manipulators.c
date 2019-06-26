#include <stdlib.h>
#include "ft_find_solution.h"

t_solution	*ft_solution_new(void)
{
	t_solution	*new;

	if (!(new = malloc(sizeof(t_solution))))
		return (NULL);
	ft_bzero(new, sizeof(t_solution));
	return (new);
}

void	ft_free_solution(t_solution **solution)
{
	t_pathlst		*tmp;
	t_pathlst		*next;

	tmp = (*solution)->pathlst;
	while (tmp != NULL)
	{
		ft_roomlst_delall(&(tmp->path));
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(*solution);
}