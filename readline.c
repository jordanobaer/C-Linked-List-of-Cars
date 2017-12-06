//readline.c is the file with the function to read a line.
//The function prototype is in "readline.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "readline.h"

//read_line will receive and array of char and the maximum number of characters n.
//The function read the line and store the input in the str[].
int read_line(char str[], int n)
{
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  str[i++] = ch;
  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;
    
   }
   str[i] = '\0';
   return i;
 }

