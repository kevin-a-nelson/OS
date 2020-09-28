#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>



void *pthreadsFunction(void*)
{
    sleep(1);
    printf("I am the PTHREAD. My pid is %d\n", getpid());
    return NULL;
}

int main()
{
    pthread_t thread_id;
    printf("I am MAIN. My pid is %d\n", getpid());
    printf("I am the MAIN, and I successfully launched a pthread.\n");
    pthread_create(&thread_id, NULL, pthreadsFunction, NULL);
    pthread_join(thread_id, NULL);
    printf("I am the MAIN, and the pthread has finished.\n");
    exit(0);
}