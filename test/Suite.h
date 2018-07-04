#ifndef SUITE_H
#define SUITE_H

#include <stdio.h>


char *testName = "no test here";
int CC;

#define TEST(name) void name(){testName = "" #name ""; printf("\e[96m" #name ":\n  "); if(5)

#define END printf("\n");}

#define ASSERT_EQUAL(AA, BB) CC = AA; if (CC != BB) printf("\n\e[91m  fail: %d != %d\n", CC, BB);\
                             else printf("\e[32m.");


#endif
