#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem;

void func1(void *arg)
{
    printf("thread1 starting and will sem_wait\n");
    sem_wait(&sem);
    int *running = arg;
    printf("thread1 sem_wait end\n");
}

void func2(void *arg)
{
    printf("thread2 starting and will sem_post\n");
    sem_post(&sem);
    printf("thread2 sem_post end\n");
}

int main()
{
    sem_init(&sem, 0, 0);
    pthread_t thread[2];
    int a = 5;
    printf("main thread starting\n");
    pthread_create(&(thread[0]), NULL, (void *)func1, (void *)&a);
    printf("main create thread1 end\n");

    sleep(10);

    pthread_create(&(thread[1]), NULL, (void *)func2, (void *)&a);
    printf("main create thread2 end\n");

    pthread_join(thread[0], NULL);
    pthread_join(thread[1], NULL);

    sem_destroy(&sem);
    return 0;
}
