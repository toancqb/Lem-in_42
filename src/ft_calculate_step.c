/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_step.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 09:29:23 by gly               #+#    #+#             */
/*   Updated: 2019/06/28 11:45:39 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static inline int	ft_get_min_step(t_pathlst *path)
{
	int		min_step;

	min_step = -1;
	while (path != NULL)
	{
		if (path->n_step < min_step || min_step == -1)
			min_step = path->n_step;
		path = path->next;
	}
	return (mint_step);
}

int					ft_calculate_step(int n_path, t_solution *solution)
{
	int			remain;
	int			min_step;
	t_pathlst	*path;

	if (n_path == 1)
		return (solution->pathlst->n_step + glob->nb_ants - 1);
	remain = glob->nb_ants % n_path;
	min_step = ft_get_min_step(solution->pathlst);
	path = solution->pathlst;
	while (path != NULL)
	{
		remain += path->n_step - min_step;
		path = path->next;
	}
	path = solution->pathlst;
	while (path != NULL)
	{
		path->nb_ants = glob->nb_ants / n_path - (path->n_step - min_step)
			+ remain / n_path + (remain % n_path ? 1 : 0);
		if (path->nb_ants <= 0)
			return (-1);
		remain -= remain % n_path ? 1 : 0;
		path = path->next;
	}
	return (solution->pathlst->nb_ants + solution->pathlst->n_step - 1);
}
