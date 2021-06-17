#include "apue.h"
#include <sys/wait.h>

int main (void)
{
    char buf[MAXLINE];
    pid_t pid;
    int status;

    printf("[BEN] my pid=%d\n",getpid());
    /* print prompt (printf requires %% to print %) */
    printf("%% ");
    /*
      fgets() : to read one line at a time from the standard input.
                When we type the end-of-file character (which is often Control-D)
                fgets returns a null pointer, the loop stops and the process terminates.
    */
    while (fgets(buf, MAXLINE, stdin) != NULL) {
        /*
          because each line returned by fgets is terminated with a newline (\n) character
          followed by a null byte, we use the standard C function strlen to calculate the length of the string
          and then replace the newline with a null byte. We do this because the execlp function wants
          a null-terminated argument, not newline-terminated argument.
        */
        if(buf[strlen(buf)-1] == '\n')
            buf[strlen(buf)-1] = 0;
        /*
          fork() to create a new process which is a copy of the caller.
          fork() returns non-negative to the parent
                        zero to the child

        */
        if((pid=fork()) < 0 ) {
            err_sys("fork error");
        } else if (pid==0) {
            /*
              in the child, we call execlp() to execute the command that was read from the standard input.
              execlp() replaces the child process with the new program file.

              Because the child called execlp() to execute the new progrm file, the parent wants to wait for the child to terminate.
              This is done by calling waitpid, specifying which process to wait for.

              execlp(const char *file, const char *arg, ...)

              A child only run the execlp() line
            */
            execlp(buf, buf, (char *)0);
            printf("[BEN] after execlp() pid=%d",pid);
            err_ret("couldn`t execute: %s\n", buf);
            exit(127);
        }
        printf("[BEN] pid=%d\n",pid);
        /*
          fork() to create a new process which is a copy of the caller.
          fork() returns non-negative to the parent
                        zero to the child

        */
        /* parent */
        if ((pid = waitpid(pid, &status, 0))<0)
            err_sys("waitpid error");
        printf("%% ");
    }
    exit(0);
}