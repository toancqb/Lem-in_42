#include "ft_lib_lem_in.h"
#include "ft_find_solution.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

t_roomlst *ft_ant_init(int nb_ant)
{
  t_roomlst *ant;

  if (nb_ant > 0)
  {
    ant = NULL;
    while (nb_ant > 0)
    {
      ft_roomlst_add(&ant, ft_roomlst_new(NULL, nb_ant));
      nb_ant--;
    }
    return (ant);
  }
  return (NULL);
}

int ft_nb_ant_in_end(int *check, int nb_ant)
{
  int i;
  int count;

  i = 1;
  count = 0;
  while (i <= nb_ant)
  {
    if (check[i] == 1)
      count++;
    i++;
  }
  return (count);
}

void ft_move_current_ant(t_roomlst *ant, t_global *g)
{
  t_roomlst *tmp;

  tmp = ant;
  while (tmp != NULL)
  {
    if (tmp->r != NULL && ft_strcmp(tmp->r->name, g->end->name))
    {
      //printf("(%s) -> ", tmp->r->name);
      tmp->r = tmp->r->p;
      //printf("(%s)\n", ant->r->name);
    }
    tmp = tmp->next;
  }
}

t_roomlst *ft_next_ant(t_roomlst *ant)
{
  t_roomlst *tmp;

  tmp = ant;
  while (tmp != NULL)
  {
    if (tmp->r == NULL)
      return (tmp);
    tmp = tmp->next;
  }
  return (NULL);
}

int ft_move(t_roomlst *ant, t_global *g)
{
  t_solution *s;
  t_pathlst *plst;
  t_roomlst *next_ant;

  s = g->solution;
  plst = s->pathlst;
  ft_move_current_ant(ant, g);
  while (plst != NULL)
  {
    if (plst->nb_ant > 0)
    {
      next_ant = ft_next_ant(ant);
      if (next_ant == NULL)
        break ;
      next_ant->r = (plst->path->next)->r;
      (plst->nb_ant)--;
    }
    plst = plst->next;
  }
  return (1);
}

void process_path(t_solution *s)
{
  t_pathlst *pathlst;
  t_roomlst *path;

  pathlst = s->pathlst;
  while (pathlst != NULL)
  {
    path = pathlst->path;
    while (path != NULL)
    {
      if (path->next)
      {
        path->r->p = path->next->r;
      //  printf("(%s) -> (%s)\n", path->r->name, path->r->p->name);
      }
      path = path->next;
    }
    pathlst = pathlst->next;
  }
}

void print_line(t_roomlst *ant, int *check, t_room *end)
{
  t_roomlst *tmp;

  tmp = ant;
  while (tmp != NULL)
  {
    if (check[tmp->rank] == 0 && tmp->r != NULL)
      printf("L%d-%s ", tmp->rank, tmp->r->name);
    if (tmp->r != NULL && !ft_strcmp(tmp->r->name, end->name))
      check[tmp->rank] = 1;
    tmp = tmp->next;
  }
  printf("\n");
}

void ft_check_init(int *check, int nb_ant)
{
  int i;

  check[nb_ant + 1] = 3;
  i = 0;
  while (i <= nb_ant)
  {
    check[i] = 0;
    i++;
  }
}

int print_lem_in_simple(t_global *g)
{
  t_roomlst *ant;
  int *check;
//  int i;

  if (!(check = (int*)malloc(sizeof(int) * (g->nb_ant + 2))))
    return (0);
  ant = ft_ant_init(g->nb_ant);
  ft_check_init(check, g->nb_ant);
  if (ant == NULL)
    return (0);
  process_path(g->solution);
  while (ft_nb_ant_in_end(check, g->nb_ant) < g->nb_ant)
  {
    ft_move(ant, g);
    print_line(ant, check, g->end);

    ft_move(ant, g);
    print_line(ant, check, g->end);
  }
  free(check);
  return (1);
}
