/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib_lem_in.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:24:47 by qtran             #+#    #+#             */
/*   Updated: 2019/07/11 15:57:35 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIB_LEM_IN_H
# define FT_LIB_LEM_IN_H
# define STDIN_DEFAULT 0
# include <string.h>
# define INT_MAX 2147483647
# define INT_MIN -2147483648

# define OPT_I 1
# define OPT_S 1 << 1
# define OPT_P 1 << 2

typedef struct			s_room
{
	char				*name;
	int 	      		ant_cur;
	int     			type;
	ssize_t				i;
	int					nb_link;
	struct s_roomlst	**link;
	int					flag;
	struct s_room 		*p;
}						t_room;

typedef struct 			s_roomlst
{
	t_room				*r;
	int					rank;
	struct s_roomlst	*next;
}						t_roomlst;

typedef struct			s_pathlst
{
	int					n_step;
	int					nb_ant;
	t_roomlst			*path;
	struct s_pathlst	*next;
}						t_pathlst;

typedef struct			s_solution
{
	int					n_total_step;
	t_pathlst			*pathlst;
}						t_solution;

typedef struct			s_global
{
	t_room				*start;
	t_room				*end;
	int					nb_room;
	int					nb_ant;
	char				*r_status;
	char				**working_path;
	t_room				**rooms;
	t_roomlst			**r_tmp;
	t_solution			*solution;
	int					n_path;
}						t_global;

/*
 * n_read = -1 haven't read nb_ant
 *
 *        = 0 had read nb_ant and ready for reading rooms
 *            (after read 1er rooms n_read = 1)
 *        = 1 had read rooms and ready for reading links
 *            (after read 1er link, n_read = 2)
 *        if n_read == 2 and we met room => Stop reading
 *        if n_read == 0 and we met link => Stop reading -> Error
 */

typedef struct s_input
{
	int type;
	int check;
	int index;
	int n_read;
} t_input;

/* room manipulators */
t_room *ft_room_init();
void ft_room_free(t_room **room);
char *ft_get_name(char *line);
t_room *ft_room_new(char *name);
t_room *ft_get_room_by_line(t_global *global, char *line, int flag);

/* roomlst manipulators */
t_roomlst *ft_roomlst_init(t_room *room);
int ft_roomlst_len(t_roomlst *lst);
void f_print_roomlst(t_roomlst *r);
t_roomlst *ft_roomlst_new(t_room *room, int rank);
void ft_roomlst_iter(t_roomlst *lst, void (*f)(t_roomlst *r));
void ft_roomlst_add(t_roomlst **lst, t_roomlst *elem);
void ft_roomlst_push(t_roomlst **lst, t_roomlst *elem);
t_roomlst *ft_roomlst_shift(t_roomlst **lst);
t_roomlst *ft_roomlst_pop(t_roomlst **lst);
void ft_roomlst_delall(t_roomlst **lst);
t_roomlst	*ft_roomlst_new(t_room *room, int rank);
void		ft_roomlst_add_rank(t_roomlst **roomlst, t_roomlst *elem);

/** global manipulators **/
t_global *ft_global_init();
void ft_global_free(t_global **global);

/* input parsing */
int ft_input_parsing(t_global *global, int opt);
int		ft_opt_input_parsing(int argc, char **argv);
int is_command(char *line);
int is_comment(char *line);
int is_nb_ant(char *line);
int is_room(char *line);
int is_link(char *line);
int ft_parse_nb_ant(char *line, t_global *global, t_input *input);
void ft_parse_command(char *line, t_input *input);
int ft_parse_room_tmp(char *line, t_global *global, t_input *input);
int ft_parse_link(char *line, t_global *global, t_input *input);
void ft_parse_room(t_global *global);

/* output */
void	ft_print_solution(t_solution *sol);
int print_lem_in_simple(t_global *g);

/* misc */
void ft_error();
void ft_strerror(char *str);
int ft_is_double_room(t_global *g, char *tmp);
int ft_check_format_line(char *line, t_input *input);
int is_in_intmax(const char *line);

#endif
