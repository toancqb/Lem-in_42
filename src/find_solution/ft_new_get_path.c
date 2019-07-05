
int		ft_get_next_room(t_global *glob, t_room *room)
{
	t_roomlst	*link;
	t_room		*tmp;

	link = *(room->link);
	tmp = NULL;
	while (link != NULL)
	{
		if (glob->working_path[link->r->i][room->i] & REV_UP)
			return (link->r);
		else if (glob->working_path[link->r->i][room->i] & ACTIVISIT
				&& !(glob->working_path[link->r->i][room->i] & REV_DOWN))
			tmp = link->r;
		link = link->next;
	}
	return (tmp);
}

int		ft_get_new_path2(t_global *glob, t_room *room, t_roomlst **path)
{
	while (room != NULL)
	{
		if (!(next_room = ft_get_next_room(glob, room)))
			return (-1);
		if (!(elem = ft_roomlst_new(next_room, 0)))
			return (-1);
		ft_roomlst_add(path, elem);
		if (next_room == glob->start)
			return (0);
		room = next_room;
	}
	return (-1);
}




int		ft_get_new_path(t_global *glob, t_roomlst **path)
{
	t_roomlst	*link;
	t_roomlst	*elem;

	link = *(glob->end->link);
	while (link != NULL)
	{
		if (glob->working_path[link->r->i][glob->end->i] & ACTIVISIT
				&& !(glob->r_status[link->r->i] & ACTIVE))
		{
			if (!(elem = ft_roomlst_new(link->r, 0)))
				return (-1);
			ft_roomlst_add(path, elem);
			if (link->r == glob->start)
				return (1);
			return (ft_get_new_path2(glob, link->r, path));
		}
		link = link->next;
	}
	return (0);
}


int		ft_check_reverse_flow(char *r_status, t_roomlst *new_path)
{
	int		flag;

	if (new_path == NULL)
		return (-1);
	flag = 0;
	while (new_path->next != NULL)
	{
		if (r_status[new_path->next->r->i] & ACTIVE)
		{
			if (r_status[new_path->r->i] & ACTIVE)
				new_path->next->rank = -2;
			else
				new_path->next->rank = -1;
			flag = 1;
		}
		else if (r_status[new_path->r->i] & ACTIVE)
		{
			flag = 1;
			new_path->rank = -3;
		}
		new_path = new_path->next;
	}
	return (flag);
}

void	ft_get_reverse_flow_limit(t_roomlst **new_path, t_roomlst **new_down_prev)
{
	t_roomlst	*tmp;

	*new_down_prev = *new_path;
	*new_path = (*new_path)->next;
	while ((*new_path)->rank != -3)
		*new_path = (*new_path)->next;
}

void	ft_switch_path(t_global *glob,
		t_roomlst *new_path, t_roomlst *new_down_prev)
{
	t_roomlst	*old_up_prev;
	t_roomlst	*old_down;

	old_up_prev = NULL;
	old_down = NULL;
	ft_find_old_path(glob, old_up_prev, old_down, new_path, new_down_prev)

}
int		ft_recombine_path(t_global *glob, t_roomlst *new_path)
{
	t_roomlst	*new_down_prev;

	while (new_path->next != NULL)
	{
		if (new_path->next->rank == -1)
			ft_get_reverse_flow_limit(&new_path, &new_down_prev);
		ft_switch_path(glob, new_path, new_down_prev);
		new_path = new_path->next;
	}
	return (0);
}

int		ft_get_path(t_global *glob, t_solution *solution)
{
	t_roomlst	*new_path;

	new_path = NULL;
	if ((ret = ft_get_new_path(glob, &new_path)) <= 0)
		return (ret);
	if (glob->n_path != 0)
	if (ft_check_reverse_flow(glob->r_status, new_path) == 1)
		ft_recombine_path(glob, new_path);
	return (0);

}
