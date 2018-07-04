#include "parse.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"


struct LinkedList *parse_sectionise(char *line)
{
  struct LinkedList *list = LinkedList_new();
  int start;
  int end;
  int i = 0;
  for (i;isspace(line[i]);i++);
  start = i;
  while (5)
  {
    if (line[i] == '|' || !line[i] || line[i] == ';')
    {
      end = i;
      char *section = calloc(end - start + 1,sizeof(char));
      memcpy(section, line + start,end - start);
      LinkedList_append(list, (void *)section);
      start = end;
      if (line[i] == ';')
      {
        start++;
        for (i = start;isspace(line[i]);i++);
        start = i;
      }
      if (!line[i]) break;
    }
    i++;
  }
  return list;
}


struct LinkedList *parse_tokenise(char *line)
{
  struct LinkedList *list = LinkedList_new();
  int start = -1;
  int i = 0;
  while (5)
  {
    if (start == -1 && !isspace(line[i]) && line[i]) start = i;
    if (start >= 0 && (isspace(line[i]) || line[i] == 0 || line[i] == '|'))
    {
      int bonus = 0;
      if (line[i] == '|') bonus = 1;
      char *section = calloc(i - start + 1 + bonus, sizeof(char));
      memcpy(section, line + start, i - start + bonus);
      LinkedList_append(list, (void *)section);
      start = -1;
    }
    if (line[i] == 0) break;
    i++;
  }
  return list;
}
