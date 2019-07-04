/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:25:04 by qtran             #+#    #+#             */
/*   Updated: 2019/07/02 14:10:36 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib_lem_in.h"
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

int main(int argc, char *argv[])
{
	test_input_parse(argc, argv);
	return (0);
}
