#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = getpid();

    printf("My PID:  %d\n", pid);

    return 0;
}
