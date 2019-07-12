/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 11:08:04 by qtran             #+#    #+#             */
/*   Updated: 2019/07/12 11:08:10 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void ft_error()
{
  ft_putstr("Error\n");
  exit(0);
}

void ft_strerror(char *str)
{
  ft_putstr("Error: ");
  ft_putstr(str);
  exit(0);
}
