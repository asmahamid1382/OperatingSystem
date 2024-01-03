#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include<pthread.h>
pthread_mutex_t mutex;

int fuel =0 ; 
void* fuel_filling(void* args)
{
    for (int i = 0; i < 5; i++)
    {
        pthread_mutex_lock(&mutex);
        fuel+=15; 
        printf("filling fuel %d \n ",fuel); 
        pthread_mutex_unlock(&mutex);
        sleep(1); 

    }
}
void* car()
{
        pthread_mutex_lock(&mutex);
        fuel-=40; 
        printf("got fuel %d \n ",fuel);
        pthread_mutex_unlock(&mutex);    

}
int main()
{
    pthread_t th[2]; 
    pthread_mutex_init(&mutex,NULL); 
    for (int i = 0; i < 2; i++)
    {
        if (i==1)
        {
        pthread_create(&th[i], NULL,&fuel_filling,NULL);
        }
        if(i==0)
        {
        pthread_create(&th[i], NULL,&car,NULL);

        }
        
    }
    for (int i = 0; i < 2; i++)
    {

        pthread_join(th[i],NULL);


    }
    
pthread_mutex_destroy(&mutex); 
}