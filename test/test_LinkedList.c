#include "suite.h"
#include "../src/LinkedList.c"


TEST(appendTest)
{
  int a = 2345723;
  int b = 6;
  int c = 1247;
  struct LinkedList *list = LinkedList_new();
  LinkedList_append(list, &a);

  ASSERT_EQUAL(*(int *)LinkedList_get(list, 0), a);

  ASSERT_EQUAL(*(int *)LinkedList_getLast(list), a);


  LinkedList_append(list, &b);

  ASSERT_EQUAL(*(int *)LinkedList_get(list, 0), a);
  ASSERT_EQUAL(*(int *)LinkedList_get(list, 1), b);

  ASSERT_EQUAL(*(int *)LinkedList_getLast(list), b);


  LinkedList_append(list, &c);

  ASSERT_EQUAL(LinkedList_size(list), 3);
  ASSERT_EQUAL(*(int *)LinkedList_get(list, 0), a);
  ASSERT_EQUAL(*(int *)LinkedList_get(list, 1), b);
  ASSERT_EQUAL(*(int *)LinkedList_get(list, 2), c);
  ASSERT_EQUAL(*(int *)LinkedList_getLast(list), c);

  LinkedList_remove(list,1);
  ASSERT_EQUAL(*(int *)LinkedList_get(list, 1), c);

  LinkedList_remove(list,0);
  ASSERT_EQUAL(LinkedList_size(list), 1);
  ASSERT_EQUAL(*(int *)LinkedList_get(list, 0), c);

  LinkedList_append(list, &b);
  LinkedList_append(list, &b);
  LinkedList_remove(list,2);
  ASSERT_EQUAL(*(int *)LinkedList_get(list, 1), b);


  LinkedList_free(list);
  END;
}


TEST(stackTest)
{
  int a = 1;
  int b = 2;

  struct LinkedList *list = LinkedList_new();

  LinkedList_push(list, &a);
  ASSERT_EQUAL(*(int *)LinkedList_pop(list), a);
  LinkedList_push(list, &b);
  LinkedList_push(list, &a);
  ASSERT_EQUAL(*(int *)LinkedList_pop(list), a);
  ASSERT_EQUAL(*(int *)LinkedList_pop(list), b);

  LinkedList_free(list);
  END;
}


int main()
{
  appendTest();
  stackTest();
  return 0;
}
