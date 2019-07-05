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
  global->nb_ant = 0;
  global->nb_room = 0;
  global->working_path = NULL;
  if (!(global->r_tmp = (t_roomlst**)malloc(sizeof(t_roomlst*))))
    exit(0);
  *(global->r_tmp) = NULL;
  global->rooms = NULL;
  global->solution = NULL;
  return (global);
}

void ft_global_free(t_global **global)
{
  int i;
  t_global *g;

  if (global && *global)
  {
    i = 0;
    g = *global;
    if (g->rooms)
      while (g->rooms[i] != NULL)
      {
        if (g->rooms[i])
          ft_room_free(&(g->rooms[i]));
        i++;
      }
    free(g->rooms);
    if (g->r_status)
      free(g->r_status);
    i = 0;
    if (g->working_path)
      while (g->working_path[i] != NULL)
      {
        if (g->working_path[i])
          free(g->working_path[i]);
        i++;
      }
    free(g->working_path);
    ft_free_solution(&(g->solution));
    free(g);
  }
}
