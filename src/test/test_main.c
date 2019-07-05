/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:25:04 by qtran             #+#    #+#             */
/*   Updated: 2019/07/05 10:52:06 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib_lem_in.h"
#include "ft_find_solution.h"
#include "libft.h"
#include <stdio.h>

//gcc main.c ft_room.c ft_input*.c ft_detect.c ft_tools.c linked_list/*.c ../libft/libft.a

void test_input_parse(int argc, char **argv)
{
	t_global *g;
	int i;

	(void)argc;
	(void)argv;
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
}

int	test_find_solution(void)
{
	t_global *g;

	g = ft_global_init();
	ft_input_parsing(g);
	printf("Le nombre de fourmi est %d\n", g->nb_ant);
	printf("START %s \n", g->start->name);
	printf("End is %s\n", g->end->name);
	ft_find_global_solution(g);
	print_solution(g);
	return (1);
}

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	//test_input_parse(argc, argv);
	test_find_solution();
	return (0);
}
