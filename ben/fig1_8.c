#include "apue.h"
#include <errno.h>

int main(int argc, char *argv[])
{
    /*
      strerror(int errnum) : change passed errnum to error message.
      EACCES: Permission denied
    */
    fprintf(stderr, "EACCES: %s\n", strerror(EACCES));
    errno = ENOENT;
    printf("argv[0] = %s\n",argv[0]);
    /*
      perror(const char *msg) : to produces an error message on the standard error ,
      based on the current value of errorno, and returns
      perror("hello"); -> hello: No such file or directory
    */
    perror("hello");
    exit(0);
}