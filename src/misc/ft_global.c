#include "ft_lib_lem_in.h"
#include "ft_find_solution.h"
#include <stdlib.h>

t_global *ft_global_init()
{
  t_global *global;

  if (!(global = (t_global*)malloc(sizeof(t_global))))
    exit(0);
  global->start = NULL;
  global->end = NULL;
  global->nb_ant = -1;
  global->nb_room = 0;
  global->working_path = NULL;
  if (!(global->r_tmp = (t_roomlst**)malloc(sizeof(t_roomlst*))))
    exit(0);
  *(global->r_tmp) = NULL;
  global->rooms = NULL;
  global->solution = NULL;
  return (global);
}

void ft_room_free(t_room **room)
{
  t_room *r;
  t_roomlst *i;
  t_roomlst *tmp;

  if (room)
  {
    r = *room;
    if (r->name)
      free(r->name);
    /*i = *(r->link);
    while (i != NULL)
    {
      tmp = i;
      i = i->next;
      free(tmp);
    }*/
    free(r->link);
    free(*room);
  }
}

void ft_global_free(t_global **global)
{
  int i;
  t_global *g;

  i = 0;
  g = *global;
  if (g->r_status)
    free(g->r_status);
  if (g->solution != NULL)
  	ft_free_solution(&(g->solution));
  while (g->rooms[i] != NULL)
  {
    ft_room_free(&(g->rooms[i]));
    i++;
  }

  free(g);
}
