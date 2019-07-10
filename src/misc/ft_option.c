#include <stdlib.h>
#include "ft_lib_lem_in.h"

t_option *ft_opt_init(void)
{
  t_option *opt;

  if (!(opt = (t_option*)malloc(sizeof(t_option))))
    return (NULL);
  opt->s = 0;
  opt->i = 0;
  opt->p = 0;
  return (opt);
}

static void process_opt(t_option *opt, char *str)
{
  if (str)
  {
    if (str[0] != '-')
      ft_strerror("Usage: ./lem-in -option < map.txt");
    else
    {
      str++;
      while (*str != '\0')
      {
        if (*str == 'i')
          opt->i = 1;
        else if (*str == 's')
          opt->s = 1;
        else if (*str == 'p')
          opt->p = 1;
        str++;
      }
    }
  }
}

void ft_opt_input_parsing(t_option *opt, int argc, char **argv)
{
  int i;

  if (argc > 1)
  {
     i = 1;
     while (i < argc)
     {
       process_opt(opt, argv[i]);
       i++;
     }
  }
}
