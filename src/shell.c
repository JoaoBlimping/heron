#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "HeronConfig.h"
#include "logo.h"

#define LOGO_BUFFER 32
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

    // Parse the command line.
    printf("%s", &line);
  }

  return 0;
}
