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

t_room *ft_room_new(char *name)
{
	t_room *r;

	r = ft_room_init();
	r->name = ft_strdup(name);
	return (r);
}

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
}

int main(void)
{
	test_roomlst();
	return (0);
}
