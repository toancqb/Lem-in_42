/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:25:04 by qtran             #+#    #+#             */
/*   Updated: 2019/06/25 12:00:11 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib_lem_in.h"
#include "libft.h"
#include <stdio.h>

//gcc main.c ft_room.c ft_input*.c ft_detect.c ft_tools.c linked_list/*.c ../libft/libft.a

void test_input_parse(int argc, char **argv)
{
	t_global *g;
	t_roomlst *tmp;
	int i;

	g = ft_global_init();
	ft_input_parsing(g);

	//test input parsing

	i = 0;
	while(i < g->nb_room)
	{
		printf("[%s] -> ", g->rooms[i]->name);
		i++;
	}
	printf("\n");
	i = 0;
	while(g->rooms[i] != NULL)
	{
		printf("\n---[%s]---:\n", g->rooms[i]->name);
		ft_roomlst_iter(*(g->rooms[i]->link), &f_print_roomlst);
		i++;
	}

	/*ft_roomlst_iter(*(g->r_tmp), &f_print_roomlst);

	tmp = *(g->r_tmp);
	while (tmp != NULL)
	{
		ft_putstr("\n--["); ft_putstr(tmp->r->name); ft_putstr("]--\n");
		ft_roomlst_iter(*(tmp->r->link), &f_print_roomlst);
		ft_putstr("\n");
		tmp = tmp->next;
	}*/
}

int main(int argc, char *argv[])
{
	test_input_parse(argc, argv);
	return (0);
}
