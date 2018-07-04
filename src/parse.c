#include "parse.h"

#include "LinkedList.h"


struct LinkedList *parse_sectionise(char *line)
{
  struct LinkedList *list = LinkedList_new();
  int start = -1;
  for (int i = 0;line[i];i++)
  {
    if (start == -1 && !isspace(line[i])) printf("%d", i);
  }
  return list;
}

struct LinkedList *parse_tokenise(char *line)
{
  return NULL;
}
