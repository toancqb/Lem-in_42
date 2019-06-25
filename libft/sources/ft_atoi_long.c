/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 20:20:39 by qtran             #+#    #+#             */
/*   Updated: 2019/04/28 20:20:42 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isdigit_long(int c)
{
	return (c >= '0' && c <= '9');
}

int		ft_isspace_long(int c)
{
	return (c == '\t' ||
			c == '\n' ||
			c == '\v' ||
			c == '\f' ||
			c == '\r' ||
			c == ' ');
}

long	ft_atoi_long(const char *str)
{
	unsigned long	result;
	unsigned long	border;
	size_t			i;
	int				sign;

	result = 0;
	border = (unsigned long)(FT_LONG_MAX / 10);
	i = 0;
	while (ft_isspace_long(str[i]))
		i++;
	sign = (str[i] == '-') ? -1 : 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit_long(str[i]))
	{
		if ((result > border || (result == border && (str[i] - '0') > 7))
															&& sign == 1)
			return (-1);
		else if ((result > border || (result == border && (str[i] - '0') > 8))
																&& sign == -1)
			return (0);
		result = result * 10 + (str[i++] - '0');
	}
	return ((long)(result * sign));
}
