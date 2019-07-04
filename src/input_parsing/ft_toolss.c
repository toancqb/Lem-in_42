#include "ft_lib_lem_in.h"
#include "libft.h"
#include <stdlib.h>

int ft_is_double_room(t_global *g, char *tmp)
{
  t_roomlst *rlst;

  rlst = *(g->r_tmp);
  while (rlst != NULL)
  {
    if (!(ft_strcmp(rlst->r->name, tmp)))
      return (0);
    rlst = rlst->next;
  }
  return (1);
}

int is_in_intmax(char *line, int len)
{
  long n;
  char *str;
  int i;

  if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
    exit(0);
  str[len] = '\0';
  i = 0;
  while (i < len)
  {
    str[i] = line[i];
    i++;
  }
  n = (long)ft_atoi_long((const char*)str);
  free(str);
  if (n > 2147483647 || n < -2147483648)
    return (0);
  return (1);
}
