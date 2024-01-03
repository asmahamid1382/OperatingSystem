#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include<pthread.h>
pthread_mutex_t mutex;
void* routine(void* args)
{
if(pthread_mutex_trylock(&mutex)==0)
{
printf("got lock \n ");
sleep(1); 
pthread_mutex_unlock(&mutex); 
} 
else
{
    printf("didnt get lock \n");
}




}
int main()
{
    pthread_t th[4]; 
    pthread_mutex_init(&mutex,NULL); 
    for (int i = 0; i < 4; i++)
    {

        pthread_create(&th[i], NULL,&routine,NULL);
    }
    for (int i = 0; i < 4; i++)
    {

        pthread_join(th[i],NULL);


    }
    
pthread_mutex_destroy(&mutex); 
}