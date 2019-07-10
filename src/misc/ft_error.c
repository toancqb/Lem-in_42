#include "libft.h"
#include <stdlib.h>

void ft_error()
{
  ft_putstr("Error\n");
  exit(0);
}

void ft_strerror(char *str)
{
  ft_putstr("Error: ");
  ft_putstr(str);
  exit(0);
}
