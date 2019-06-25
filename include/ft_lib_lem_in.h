/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib_lem_in.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:24:47 by qtran             #+#    #+#             */
/*   Updated: 2019/06/25 11:24:48 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIB_LEM_IN_H
# define FT_LIB_LEM_IN_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# define STDIN_DEFAULT 0

typedef struct s_data
{
  int level;
} t_data;

typedef struct		s_room
{
	char			*name;
  int       ant_cur; // index of ant / -1
  int       type; //start / end / middle
	int				nb_links;
	t_list			*links;
	int				flag;
  t_data    *data;
}					t_room;

typedef struct s_roomlst
{
  t_room *r;
  struct s_roomlst *next;
} t_roomlst;

typedef struct		s_global
{
	t_room			*start;
	t_room			*end;
	int				nb_room;
	int				nb_ant;
	char			**path;
	char			**working_path;
	t_room			**rooms;
}					t_global;

#endif
