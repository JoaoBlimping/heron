#ifndef SUITE_H
#define SUITE_H

#include <stdio.h>


char *testName = "no test here";
int INT_HOLDER;
char *STRING_HOLDER;

#define TEST(name) void name(){testName = "" #name ""; printf("\e[96m" #name ":\n  "); if(5)

#define END printf("\n");}

#define ASSERT_EQUAL(AA, BB) INT_HOLDER = AA;\
                             if (INT_HOLDER != BB)\
                             {\
                               printf("\n\e[91m  fail: %d != %d\n", INT_HOLDER, BB);\
                             }\
                             else printf("\e[32m.");

#define ASSERT_STR(AA, BB) STRING_HOLDER = AA;\
                           if (strcmp(STRING_HOLDER, BB))\
                           {\
                             printf("\n\e[91m  fail: '%s' != '%s'\n", STRING_HOLDER, BB);\
                           }\
                           else printf("\e[32m.");


#endif
