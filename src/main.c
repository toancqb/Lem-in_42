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

#include "../include/ft_lib_lem_in.h"

//gcc main.c ft_room.c linked_list/*.c ../libft/libft.a

void test_roomlst()
{
	t_roomlst *lst;
	t_roomlst *tmp;
	//test add
	ft_putstr("test add \n");
	lst = NULL;
	ft_roomlst_add(&lst, ft_roomlst_init(ft_room_new("111")));
	ft_roomlst_add(&lst, ft_roomlst_init(ft_room_new("222")));
	ft_roomlst_add(&lst, ft_roomlst_init(ft_room_new("333")));
	ft_roomlst_iter(lst, &f_print_roomlst);
	ft_roomlst_delall(&lst);
	//test push
	ft_putstr("test push \n");
	lst = NULL;
	ft_roomlst_push(&lst, ft_roomlst_init(ft_room_new("111")));
	ft_roomlst_push(&lst, ft_roomlst_init(ft_room_new("222")));
	ft_roomlst_push(&lst, ft_roomlst_init(ft_room_new("333")));
	ft_roomlst_push(&lst, ft_roomlst_init(ft_room_new("444")));
	ft_roomlst_iter(lst, &f_print_roomlst);

	ft_putstr("test pop \n");
	tmp = ft_roomlst_pop(&lst);
	ft_roomlst_iter(lst, &f_print_roomlst);
	ft_putstr("pop: ");
	f_print_roomlst(tmp);

	ft_putstr("test shift \n");
	lst = NULL;
	ft_roomlst_push(&lst, ft_roomlst_init(ft_room_new("111")));
	ft_roomlst_push(&lst, ft_roomlst_init(ft_room_new("222")));
	ft_roomlst_push(&lst, ft_roomlst_init(ft_room_new("333")));
	ft_roomlst_push(&lst, ft_roomlst_init(ft_room_new("444")));
	ft_roomlst_iter(lst, &f_print_roomlst);

	ft_putstr("test shift \n");
	tmp = ft_roomlst_shift(&lst);
	ft_roomlst_iter(lst, &f_print_roomlst);
	ft_putstr("shift: ");
	f_print_roomlst(tmp);

	ft_roomlst_delall(&lst);

	ft_putstr("test add seconde \n");
	lst = NULL;
	ft_roomlst_push(&lst, ft_roomlst_init(ft_room_new("111")));
	ft_roomlst_push(&lst, ft_roomlst_init(ft_room_new("222")));
	ft_roomlst_push(&lst, ft_roomlst_init(ft_room_new("333")));
	ft_roomlst_push(&lst, ft_roomlst_init(ft_room_new("444")));

	ft_roomlst_add_second(&lst, ft_roomlst_init(ft_room_new("zzz")));
	ft_roomlst_iter(lst, &f_print_roomlst);
	ft_roomlst_delall(&lst);
}

//gcc main.c ft_room.c ft_input*.c ft_detect.c ft_tools.c linked_list/*.c ../libft/libft.a

void test_input_parse(int argc, char **argv)
{
	t_global *g;
	t_roomlst *tmp;

	g = ft_global_init();
	ft_input_parsing(g);

	//test input parsing

	ft_roomlst_iter(*(g->rooms), &f_print_roomlst);

	tmp = *(g->rooms);
	while (tmp != NULL)
	{
		ft_putstr("\n--["); ft_putstr(tmp->r->name); ft_putstr("]--\n");
		ft_lstiter(*(tmp->r->link), &f_print_tlist);
		ft_putstr("\n");
		tmp = tmp->next;
	}



}

int main(int argc, char *argv[])
{
	//test_roomlst();
	test_input_parse(argc, argv);
	return (0);
}
