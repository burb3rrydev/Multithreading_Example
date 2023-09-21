#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_MESSAGES 10

void *thread1_function(void *arg) {
    for (int i = 1; i <= NUM_MESSAGES; i++) {
        printf("Thread 1: Message %d\n", i);
        sleep(1);
    }

    pthread_exit(NULL);
}

void *thread2_function(void *arg) {
    for (int i = 1; i <= NUM_MESSAGES; i++) {
        printf("Thread 2: Message %d\n", i);
        sleep(2);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;

    // Create thread 1
    if (pthread_create(&thread1, NULL, thread1_function, NULL) != 0) {
        perror("pthread_create");
        return 1;
    }

    // Create thread 2
    if (pthread_create(&thread2, NULL, thread2_function, NULL) != 0) {
        perror("pthread_create");
        return 1;
    }

    // Wait for both threads to finish
    if (pthread_join(thread1, NULL) != 0) {
        perror("pthread_join");
        return 1;
    }

    if (pthread_join(thread2, NULL) != 0) {
        perror("pthread_join");
        return 1;
    }

    printf("Main thread: All threads have finished. Exiting...\n");

    return 0;
}
