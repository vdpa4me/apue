#include "apue.h"

#define BUFFSIZE 4096

int main (void)
{
    int n;
    char buf[BUFFSIZE];
    /*
       STDIN_FILENO and STDOUT_FILENO are contained in unistd.h
       STDIN_FILENO (0): Standard input,
       STDOUT_FILENO (1): standard output, display data to terminal

       ./fig1_4 < infile > outfile  -> contents in the infile is redirected to the outfile
    */
    /*
       read() returns # of bytes that are read.
              returns 0 when the end of of the input file is encountered
              returns -1 if a read error occurs
    */
    while((n=read(STDIN_FILENO, buf, BUFFSIZE))>0)
        if (write(STDOUT_FILENO, buf, n)!=n)
            err_sys("write error");
    
    if (n<0)
        err_sys("read error");
    
    exit(0);
}