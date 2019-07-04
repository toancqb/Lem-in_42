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
  //Je ne comprends pas trop a quoi ca sert toute cette partie avec la copie de line dans str. J'avais fait un truc similaire pour push_swap. Je te mets le code en bas.
  free(str);
  if (n > 2147483647 || n < -2147483648)
    return (0);
  return (1);
}

/*
#include <limits.h>
static int	ft_int_array(const char *str)
{
	int			i;
	long long	nb;
	int			sign;

	i = 0;
	nb = 0;
	sign = str[i] == '-' ? -1 : 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		nb *= 10;
		nb += str[i] - 48;
		if (nb > INT_MAX || nb < INT_MIN)
			return (0);
		i++;
	}
	nb *= sign;
	return (1);
}
*/
