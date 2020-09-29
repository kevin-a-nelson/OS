#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

int val = 12;
pthread_mutex_t count_mutex;

void *pthreadsFunction(void*)
{
    pthread_mutex_lock(&count_mutex);
    val += 1;
    pthread_mutex_unlock(&count_mutex);
    sleep(1);
    printf("I am the PTHREAD. My pid is %d\n", getpid());
    return NULL;
}

int main()
{
    pthread_t thread_id;
    printf("Val is %d\n", val);
    printf("I am MAIN. My pid is %d\n", getpid());
    printf("I am the MAIN, and I successfully launched a pthread.\n");
    pthread_create(&thread_id, NULL, pthreadsFunction, NULL);
    pthread_join(thread_id, NULL);
    printf("I am the MAIN, and the pthread has finished.\n");
    printf("Val is now %d\n", val);
    exit(0);
}