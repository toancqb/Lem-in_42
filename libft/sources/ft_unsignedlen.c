/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignedlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 12:51:40 by qtran             #+#    #+#             */
/*   Updated: 2019/04/22 12:51:42 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_unsignedlen(uintmax_t number, unsigned int base)
{
	size_t	size;

	if (base >= 2)
	{
		size = 1;
		while ((number /= base))
			size++;
	}
	else
		size = 0;
	return (size);
}
