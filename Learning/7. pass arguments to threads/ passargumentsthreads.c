#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include<pthread.h>
int primes[10]={2,3,5,7,11,13,17,19,23,29};
void* routine(void* args)
{
    int index = *(int*)args; 
    printf("%d ", primes[index]);
    free(args);
}
int main()
{
    pthread_t th[10]; 
    for (int i = 0; i < 10; i++)
    {
        int* a = malloc(sizeof(int));
        *a=i;
        pthread_create(&th[i], NULL,&routine,a);
    }
    for (int i = 0; i < 10; i++)
    {
        pthread_join(th[i],NULL);
    }
}