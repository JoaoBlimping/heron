#include "suite.h"
#include "../src/LinkedList.c"
#include "../src/parse.c"

TEST(sectionTest)
{
  char *input = "a|b| grep pingo  -gv   -f|echo yes; print nerd  ";
  struct LinkedList *sections = parse_sectionise(input);
  ASSERT_STR((char *)LinkedList_get(sections, 0), "a");
  ASSERT_STR((char *)LinkedList_get(sections, 1), "|b");
  ASSERT_STR((char *)LinkedList_get(sections, 2), "| grep pingo  -gv   -f");
  ASSERT_STR((char *)LinkedList_get(sections, 3), "|echo yes");
  ASSERT_STR((char *)LinkedList_get(sections, 4), "print nerd  ");
  ASSERT_EQUAL(LinkedList_size(sections), 5);
  LinkedList_free(sections);
  END;
}


TEST(tokenTest)
{
  char *input = "|grep pingo \n -gv -f a";
  struct LinkedList *sections = parse_tokenise(input);
  ASSERT_STR((char *)LinkedList_get(sections, 0), "|");
  ASSERT_STR((char *)LinkedList_get(sections,1), "grep");
  ASSERT_STR((char *)LinkedList_get(sections,2), "pingo");
  ASSERT_STR((char *)LinkedList_get(sections,3), "-gv");
  ASSERT_STR((char *)LinkedList_get(sections,4), "-f");
  LinkedList_free(sections);

  input = "|b";
  sections = parse_tokenise(input);
  ASSERT_EQUAL(LinkedList_size(sections), 2);
  ASSERT_STR((char *)LinkedList_get(sections, 0), "|");
  ASSERT_STR((char *)LinkedList_get(sections, 1), "b");
  END;
}


int main()
{
  sectionTest();
  tokenTest();
  return 0;
}
