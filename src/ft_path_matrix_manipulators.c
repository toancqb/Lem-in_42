/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_matrix_new.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:52:46 by gly               #+#    #+#             */
/*   Updated: 2019/06/25 12:00:04 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_lib_lem_in.h"

char	**ft_path_matrix_new(int nb_rooms)
{
	char	**matrix;
	size_t	i;

	if (!(matrix = malloc(sizeof(char *) * (nb_rooms))))
		return (NULL);
	i = 0;
	while (i < nb_rooms)
	{
		if (!(matrix[i] = ft_strnew(nb_rooms)))
			return (NULL);
		i++;
	}
	return (matrix);
}

char	**ft_path_matrix_cpy(char **matrix)
{
	char	**cpy;
	size_t	i;

	if (!(cpy = malloc(sizeof(char *) * (nb_rooms))))
		return (NULL);
	i = 0;
	while (i < nb_rooms)
	{
		if (!(cpy[i] = ft_strndup(matrix[i], nb_rooms)))
			return (NULL);
		i++;
	}
	return (cpy);
}
