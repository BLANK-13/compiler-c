#ifndef GLOBAL_H_
#define GLOBAL_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define BSIZE  128
#define NONE   -1
#define EOS    '\0'
#define NUM     256
#define DIV       257
#define MOD    258
#define ID          259
#define DONE   260
//FILE * input, output, err;
int lookahead;
int tokenval; int lineno;
struct entry {
   char *lexptr;
   int token;
  };
   
#endif

