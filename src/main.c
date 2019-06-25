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

void f_print(t_list *elem)
{
	ft_putstr((char*)elem->content);
	ft_putstr("\n");
}

void test_lst()
{
	t_list *master;
	char *s;

	ft_lstadd(&master, ft_lstnew((void*)"111", 3));
	ft_lstadd(&master, ft_lstnew((void*)"222", 3));
	ft_lstiter(master, &f_print);
	ft_putstr(s);
}

int main(void)
{
	test_lst();
	return (0);
}
