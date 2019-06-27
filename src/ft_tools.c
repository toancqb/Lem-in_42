#include "../include/ft_lib_lem_in.h"

char *ft_get_name(char *line)
{
  char *name;
  int i;

  i = 0;
  while (line[i] != '\0' && line[i] != ' ')
    i++;
  name = (char*)malloc(sizeof(char) * (i + 1));
  name[i] = '\0';
  i = 0;
  while (line[i] != '\0' && line[i] != ' ')
  {
    name[i] = line[i];
    i++;
  }
  return (name);
}
