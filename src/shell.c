#include "HeronConfig.h"
#include "logo.h"
#include "LinkedList.h"
#include "parse.h"
#include "execution.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


#define LINE_BUFFER 1024


void readFile(char *buffer, int bufferLength, int source)
{
  int i = read(STDIN_FILENO, buffer, LINE_BUFFER - 1);
  if (i >= 0) buffer[i] = 0;
  else fprintf(stderr, "can't read file %d\n", source);
}


void readCommandLine(char *buffer, int bufferLength)
{
  readFile(buffer, bufferLength, STDIN_FILENO);
}


int main(char **argv,int argc)
{
  char line[LINE_BUFFER];

  printf(LOGO, Heron_VERSION_MAJOR, Heron_VERSION_MINOR);

  while (5)
  {
    printf(">");
    fflush(stdout);
    readCommandLine(line, LINE_BUFFER);

    struct LinkedList *sections = parse_sectionise(line);
    struct Node *section = sections->start;
    do
    {
      struct LinkedList *tokens = parse_tokenise(section->item);
      execution_run(tokens);
      section = section->next;
    }
    while(section != NULL);
  }

  return 0;
}
