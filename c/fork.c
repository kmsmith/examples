#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid;
    int status, i;

    for (i = 0; i < 4; i++) {
        if ((pid = fork()) < 0) {
            perror("fork error");
        }
        else if (pid == 0) { /* child */
            sleep(i);
            exit(i);
        }
    }


/*
** pid_t waitpid(pid_t pid, int* status, int options);
**
** Establishing the wait set
**   if pid is -1, the wait set is all children
**   otherwise, the set consists of the child with the given pid
**
** Checking the status
**   WIFEXITED(status) - true if child exited normally
**   WEXITSTATUS(status) - returns exit code if WIFEXITED(status) is true
**   WIFSIGNALED(status) - true if child exited because it didn't catch a signal
**   WTERMSIG(status) - returns the signal that killed the child if WIFSIGNALED(status) is true
**   WIFSTOPPED(status) - true if the child is stopped
**   WSTOPSIG(status) - returns the signal that stopped the child if WIFSTOPPED(status) is true
**
** Specifying options
**   default (0) is to wait indefinitely for a child to exit or stop
**   WNOHANG - return immediately with 0 if no child has stopped or exited
**   WUNTRACED - wait indefinitely
**
** errno
**   if the parent has no children, waitpid() will return -1 and set errno to ECHILD
**   if waitpid() is interrupted by a signal, it returns -1 and sets errno to EINTR
*/


    /* parent */
    while ((pid = waitpid(-1, &status, 0)) > 0) {  /* wait indefinitely (0) for all children (-1) */
        if (WIFEXITED(status)) {
            printf("child %d terminated normally with exit status %d\n", pid, WEXITSTATUS(status));
        }
        else {
            printf("child %d terminated abnormally\n", pid);
        }
    }

    /* after all children have been reaped, waitpid() should return -1 and set errno to ECHILD */
    if (errno != ECHILD) {
        perror("waitpid error");
    }

    exit(0);
}

