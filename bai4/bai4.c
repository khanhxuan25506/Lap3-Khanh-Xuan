#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

pid_t child_pid;

void handle_sigint(int sig) {
    printf("\nYou are pressed CTRL+C! Goodbye!\n");
    kill(child_pid, SIGKILL);
    exit(0);
}

int main() {
    printf("Welcome to LOP ITCT12403, I am CT240032!\n");
    signal(SIGINT, handle_sigint);
    child_pid = fork();
    if(child_pid == 0) {
        execlp("vi", "vi", "abcd.txt", NULL);
    } else {
        wait(NULL);
    }
    return 0;
}
