/** @file LinkedList.h
 * Contains a Linked List implementation. Has structs for the linked list and the nodes in the list,
 * as well as functions for the handling of the list. */
#ifndef LINKED_LIST_H
#define LINKED_LIST_H


/** a node in the linked list which links on to the next node */
struct Node
{
  /** the next node in the linked list or null if this is the last node */
  struct Node *next;
  /** the data item that the node holds */
  void *item;
};

/** contains a whole linked list with a pointer to the start node and the end node */
struct LinkedList
{
  /** the first node in the list */
  struct Node *start;
  /** the last node in the list */
  struct Node *end;
};


/** allocated a new linked list
 * @return a pointer to your new linked list */
struct LinkedList *LinkedList_new();

/** frees an allocated linked list and it's nodes, but not the data items in it's nodes.
 * @param list is the list to be freed */
void LinkedList_free(struct LinkedList *list);

/** gets the node at a given index in the list
 * @param list is the list
 * @param index is the index in the list we are getting from
 * @return the node at that index, not the data item */
void *LinkedList_get(struct LinkedList *list, int index);

/** gets you the last item in the list. This is faster than using get to get it by far because get
 * is linear time and this is constant time.
 * @param list is the list
 * @return the data in that node */
void *LinkedList_getLast(struct LinkedList *list);

/** adds a newly allocated node to the end of the list and puts given data in it
 * @param list is the list to which it must be added
 * @param item is the data item to be added to the list */
void LinkedList_append(struct LinkedList *list, void *item);

/** Removes an element at a given index in the list and patches up the links
 * @param list is the list in question
 * @param index is the index of the thing to remove
 * @return the item in the deleted node for old time's sake */
void *LinkedList_remove(struct LinkedList *list, int index);

/** removes the first node in the list and returns it.
 * @param list is the list
 * @return the item popped */
void *LinkedList_pop(struct LinkedList *list);

/** adds a newly allocated node to the front of the list and puts given data in it
 * @param list is the list to which it must be added
 * @param item is the data item to be added to the list */
void LinkedList_push(struct LinkedList *list, void *item);

/** Tells you the length of the list
 * @param list isz the list
 * @return the list's length */
int LinkedList_size(struct LinkedList *list);


#endif
