/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 11:09:43 by qtran             #+#    #+#             */
/*   Updated: 2019/07/16 16:06:21 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib_lem_in.h"
#include "libft.h"
#include <stdlib.h>

char	*ft_get_name(char *line)
{
	char	*name;
	int		i;

	i = 0;
	while (line[i] != '\0' && line[i] != ' ')
		i++;
	if (!(name = (char*)malloc(sizeof(char) * (i + 1))))
		exit(0);
	name[i] = '\0';
	i = 0;
	while (line[i] != '\0' && line[i] != ' ')
	{
		name[i] = line[i];
		i++;
	}
	return (name);
}

char	*ft_get_first_tier(char *line)
{
	int		i;
	char	*s;

	i = 0;
	while (line[i] != '\0' && line[i] != '-')
		i++;
	if (!(s = (char*)malloc(sizeof(char) * (i + 1))))
		exit(0);
	s[i] = '\0';
	i = 0;
	while (line[i] != '\0' && line[i] != '-')
	{
		s[i] = line[i];
		i++;
	}
	return (s);
}

char	*ft_get_second_tier(char *line)
{
	int		i;
	char	*s;
	int		len;

	i = 0;
	while (line[i] != '\0' && line[i] != '-')
		i++;
	i++;
	len = i;
	while (line[i] != '\0')
		i++;
	if (!(s = (char*)malloc(sizeof(char) * (i - len + 1))))
		exit(0);
	s[i - len] = '\0';
	i = 0;
	while (line[len] != '\0')
	{
		s[i] = line[len];
		i++;
		len++;
	}
	return (s);
}

t_room	*ft_get_room_by_line(t_global *global, char *line, int flag)
{
	t_roomlst	*tmp;
	char		*s;

	s = (flag == 0) ? ft_get_first_tier(line) : ft_get_second_tier(line);
	tmp = *(global->r_tmp);
	while (tmp != NULL)
	{
		if (!ft_strcmp(tmp->r->name, s))
		{
			free(s);
			return (tmp->r);
		}
		tmp = tmp->next;
	}
	free(s);
	return (NULL);
}
