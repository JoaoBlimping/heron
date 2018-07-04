/** @file execution.h
 * Here are functions used in the execution of commands and also the carting about of their
 * outputted data. */
#ifndef EXECUTION_H
#define EXECUTION_H

#include "LinkedList.h"

/** Executes a given section of commands. The first item in the list will be considered as either
 * the command itself to be executed, or |, which means a previously executed section's output
 * should be written to stdin.
 * @param section is a list of tokens with no white space */
void execution_run(struct LinkedList *section);


#endif
