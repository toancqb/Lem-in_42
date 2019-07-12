/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toolss.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 11:10:00 by qtran             #+#    #+#             */
/*   Updated: 2019/07/12 11:10:02 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib_lem_in.h"
#include "libft.h"
#include <stdlib.h>

int ft_is_double_room(t_global *g, char *tmp)
{
  t_roomlst *rlst;

  rlst = *(g->r_tmp);
  while (rlst != NULL)
  {
    if (!(ft_strcmp(rlst->r->name, tmp)))
      return (0);
    rlst = rlst->next;
  }
  return (1);
}

int	is_in_intmax(const char *str)
{
	int			i;
	long long	nb;
	int			sign;

	i = 0;
	nb = 0;
	sign = str[i] == '-' ? -1 : 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		nb *= 10;
		nb += str[i] - 48;
		if (nb > INT_MAX || nb < INT_MIN)
			return (0);
		i++;
	}
	nb *= sign;
	return (1);
}

int ft_check_format_line(char *line, t_input *input)
{
  if (!(line[0] == '\0'))
    return (1);
  else
  {
    input->check = 1;
    return (0);
  }
}
