#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

pthread_t t1,t2;

void *thread()
{
    printf("Executing thread\n");
    sleep(2);
    printf("Finished execution\n");
}

int main()
{
    pthread_create(&t1,NULL,&thread,NULL);
    pthread_create(&t2,NULL,&thread,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    return 0;
}