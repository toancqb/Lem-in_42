/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:10:47 by qtran             #+#    #+#             */
/*   Updated: 2019/07/16 16:12:44 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib_lem_in.h"
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

t_input		*ft_input_init(void)
{
	t_input *input;

	if (!(input = (t_input*)malloc(sizeof(t_input))))
		exit(0);
	input->type = -1;
	input->index = 0;
	input->check = 0;
	input->detect = 0;
	input->n_read = -1;
	return (input);
}

int			ft_fin(ssize_t size, char **line, t_input **input)
{
	int c;

	if ((*input)->check && *line)
		free(*line);
	c = (*input)->detect;
	free(*input);
	if (size == -1)
		perror("Error GNL: ");
	if (c == -1)
		return (-1);
	return (0);
}

int			ft_check_input(t_global *g)
{
	if (g->nb_ant == -1 || g->start == NULL || g->end == NULL)
		return (-1);
	return (0);
}

static int	ft_break_gnl(t_global *global, t_input *input, char *line)
{
	input->detect = ft_check_format_line(line, input);
	if (input->detect == 0 || input->detect == -1)
		return (1);
	if (input->detect == 1 && (!ft_parse_nb_ant(line, global, input)))
		return (1);
	else if (input->detect == 2)
		ft_parse_command(line, input);
	else if (input->detect == 3
			&& (!(ft_parse_room_tmp(line, global, input))))
		return (1);
	else if (input->detect == 4
			&& (!ft_parse_link(line, global, input)))
		return (1);
	return (0);
}

int			ft_input_parsing(t_global *global, int opt)
{
	ssize_t	size;
	char	*line;
	t_input	*input;

	input = ft_input_init();
	while ((size = get_next_line(STDIN_DEFAULT, &line)) > 0)
	{
		if (!is_comment(line) && ft_break_gnl(global, input, line))
			break ;
		if (!(opt & OPT_S))
			ft_putendl(line);
		free(line);
		line = NULL;
	}
	ft_parse_room(global);
	if (ft_fin(size, &line, &input) == -1)
		return (-1);
	return (ft_check_input(global));
}
