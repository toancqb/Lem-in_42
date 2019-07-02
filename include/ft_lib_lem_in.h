/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib_lem_in.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:24:47 by qtran             #+#    #+#             */
/*   Updated: 2019/06/28 12:31:24 by gly              ###   ########.fr       */
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
  ssize_t   i;
	int				nb_link;
	struct s_roomlst			**link;
	int				flag;
  t_data    *data;
}					t_room;

typedef struct s_roomlst
{
  t_room *r;
  int		rank;
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
	t_roomlst			**rooms;
}					t_global;

t_global *ft_global_init();
t_room *ft_room_init();
t_room *ft_room_new(char *name);
void ft_room_free(t_room **room);
char *ft_get_name(char *line);
t_room *ft_get_room_by_line(t_global *global, char *line, int flag);
t_roomlst *ft_roomlst_init(t_room *room);
int ft_roomlst_len(t_roomlst *lst);
void f_print_roomlst(t_roomlst *r);
void f_print_tlist(t_list *elem);
void ft_roomlst_iter(t_roomlst *lst, void (*f)(t_roomlst *r));
void ft_roomlst_add(t_roomlst **lst, t_roomlst *elem);
void ft_roomlst_add_second(t_roomlst **lst, t_roomlst *elem);
void ft_roomlst_push(t_roomlst **lst, t_roomlst *elem);
t_roomlst *ft_roomlst_shift(t_roomlst **lst);
t_roomlst *ft_roomlst_pop(t_roomlst **lst);
void ft_roomlst_delall(t_roomlst **lst);

int is_command(char *line);
int is_comment(char *line);
int is_nb_ant(char *line);
int is_room(char *line);
int is_link(char *line);
void ft_parse_nb_ant(char *line, t_global *global);
void ft_parse_command(char *line, int *type);
void ft_parse_room(char *line, t_global *global, int *type, int *index);
int ft_input_parsing(t_global *global);
void ft_parse_link(char *line, t_global *global);

#endif
