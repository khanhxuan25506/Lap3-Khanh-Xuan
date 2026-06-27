#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *thread_func(void *arg) {
    printf("Thread dang chay!\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t tid;
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    pthread_create(&tid, &attr, thread_func, NULL);
    pthread_attr_destroy(&attr);

    sleep(1);
    printf("Main thread ket thuc!\n");
    return 0;
}
