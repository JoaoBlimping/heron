#include "LinkedList.h"
#include <stdlib.h>


struct LinkedList *LinkedList_new()
{
  struct LinkedList *list = malloc(sizeof(struct LinkedList));
  list->start = NULL;
  list->end = NULL;
}


void LinkedList_free(struct LinkedList *list)
{
  struct Node *node = list->start;
  if (node)
  {
    while (node->next != NULL)
    {
      struct Node *temp = node->next;
      free(node);
      node = temp;
    }
  }
  free(list);
}


void LinkedList_append(struct LinkedList *list, void *item)
{
  struct Node *node = malloc(sizeof(struct Node));
  node->item = item;
  node->next = NULL;
  if (list->end == NULL) list->start = node;
  else list->end->next = node;
  list->end = node;
}


void LinkedList_push(struct LinkedList *list, void *item)
{
  struct Node *node = malloc(sizeof(struct Node));
  node->item = item;
  node->next = list->start;
  list->start = node;
}


void *LinkedList_pop(struct LinkedList *list)
{
  if (list->start == NULL) return NULL;
  struct Node *old = list->start;
  void *item = old->item;
  list->start = old->next;
  free(old);
  return item;
}


void *LinkedList_get(struct LinkedList *list, int index)
{
  if (list->start == NULL) return NULL;
  struct Node *node = list->start;
  for (int i = 0; i < index; i++) node = node->next;
  return node->item;
}


void *LinkedList_getLast(struct LinkedList *list)
{
  return list->end->item;
}


void *LinkedList_remove(struct LinkedList *list, int index)
{
  if (list->start == NULL) return NULL;

  struct Node *prior = list->start;
  for (int i = 0; i < index - 1; i++) prior = prior->next;

  if (index == 0)
  {
    void *item = prior->item;
    list->start = prior->next;
    free(prior);
    return item;
  }

  void *item = prior->next->item;
  struct Node *target = prior->next;
  if (prior == list->end) list->end = prior;
  else prior->next = prior->next->next;
  free(target);
  return item;
}
