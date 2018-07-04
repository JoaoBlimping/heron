#include "execution.h"

#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


void execution_run(struct LinkedList *section)
{
  int length = LinkedList_size(section);
  if (!length) return;
  char *start = LinkedList_get(section, 0);
  if (start[0] == '|')
  {
    // do the piping stuff
    start = LinkedList_get(section, 1);
  }

  // Ok, now we begin.
  pid_t id = fork();
  if (id > 0)
  {
    int status;
    waitpid(id, &status, 0);
    printf("%d\n", WEXITSTATUS(status));
  }
  else if (id == 0)
  {
    for (int i = 0;i < 5;i++) printf("%d\n",i);
    exit(0);
  }
}
