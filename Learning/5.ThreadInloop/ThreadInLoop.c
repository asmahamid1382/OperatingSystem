#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int mails = 0;
// int lock =0 ; 
pthread_mutex_t mutex ; 
void *Function()
{
    for (int i = 0; i < 100000000; i++)
    {
        // while (lock==1)
        // {
        //     //wait untill lock is 0 
        // }
        
        // lock =1 ; 
        pthread_mutex_lock(&mutex);
        mails++;
        pthread_mutex_unlock(&mutex);
        // lock =0 ; 
        /// read the value
        /// increment
        ///  write back to memmory
    }
}

int main(int argc, char const *argv[])
{
    pthread_t t[5]; 
    pthread_mutex_init(&mutex,NULL); 
    for (int i = 0; i < 5; i++)
        pthread_create(&t[i], NULL, &Function, NULL);
    
    for (int i = 0; i < 5; i++)
    {
        pthread_join(t[i], NULL);
    }
    
    

    pthread_mutex_destroy(&mutex);
    printf("number of mails:%d\n", mails);

    return 0;
}
