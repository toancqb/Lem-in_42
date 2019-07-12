/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lem_in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 11:07:22 by qtran             #+#    #+#             */
/*   Updated: 2019/07/12 11:07:31 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib_lem_in.h"
#include "ft_find_solution.h"
#include "ft_printf.h"
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
    if (tmp->r != NULL && tmp->r != g->end)
      tmp->r = tmp->r->p;
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
        path->r->p = path->next->r;
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
      ft_printf("L%d-%s ", tmp->rank, tmp->r->name);
    if (tmp->r != NULL && tmp->r == end)
      check[tmp->rank] = 1;
	/*la ca serait mieux de retirer les tmp qui sont a end,
   *sinon a chaque fois tu parcoures beaucoup de room inutiles.
   *Apres, avec les tests ca va assez vite donc pas vraiment necessaire.
   */
    tmp = tmp->next;
  }
  ft_putstr("\n");
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

  if (!(check = (int*)malloc(sizeof(int) * (g->nb_ant + 2))))
    return (0);
  ant = ft_ant_init(g->nb_ant);
  ft_check_init(check, g->nb_ant);
  if (ant == NULL)
    return (0);
  if (g->solution)
    process_path(g->solution);
  else
    return (-1);
    ft_putstr("\n");
  while (ft_nb_ant_in_end(check, g->nb_ant) < g->nb_ant)
	  //je pense que le nb_ant_in_end peut etre juste un compteur (int)n et a chaque ft_move tu returns le nombre de fourmi qui ont atteint end et tu ajoutes a n. Optionnel aussi.
  {
    ft_move(ant, g);
    print_line(ant, check, g->end);
  }
  ft_roomlst_delall(&ant);
  free(ant);
  free(check);
  return (1);
}
