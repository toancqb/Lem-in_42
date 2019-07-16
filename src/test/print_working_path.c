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
			printf("%d%d%d%d, ",
					glob->working_path[i][j] & REV_UP ? -1 : 0,
					glob->working_path[i][j] & REV_DOWN ? -1 : 0,
					glob->working_path[i][j] & ACTIVE ? 1 : 0,
					glob->working_path[i][j] & VISITED ? 1 : 0);
			j++;
		}
		puts("");
		i++;
	}
}
