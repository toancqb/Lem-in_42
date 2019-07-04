#include "ft_lib_lem_in.h"
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
/* need to implement
void ft_global_free(t_global **g)
{

}
*/
