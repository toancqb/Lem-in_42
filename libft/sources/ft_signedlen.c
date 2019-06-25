/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signedlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 12:45:47 by qtran             #+#    #+#             */
/*   Updated: 2019/04/22 12:45:51 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_signedlen(intmax_t number, unsigned int base)
{
	size_t	size;

	size = ft_unsignedlen((uintmax_t)FT_ABS(number), base);
	return (size + ((number < 0 && size) ? 1 : 0));
}
