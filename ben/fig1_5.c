#include "apue.h"
/*
   Standard IO : provide a buffered interface to the unbuffered I/O functions.
   fgets() reads entier lines
   read() reads a specified number of bytes
   getc() reads one character at a time, and this character is written by puts.
          after the last byte of input has been read, getc returns the constant EOF(defined in <stdio.h>)

*/
int main (void)
{
    int c;
    while ((c=getc(stdin)) != EOF)
        if (putc(c, stdout) == EOF)
            err_sys("output error");
    
    if (ferror(stdin))
        err_sys("input error");
    exit(0);
}