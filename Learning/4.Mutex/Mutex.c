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
    pthread_t t1, t2;
    pthread_mutex_init(&mutex,NULL); 
    pthread_create(&t1, NULL, &Function, NULL);
    pthread_create(&t2, NULL, &Function, NULL);
    pthread_join(t1, NULL); // the second argument is for getting the result of the function
    pthread_join(t2, NULL);
    pthread_mutex_destroy(&mutex);
    printf("number of mails:%d\n", mails);

    return 0;
}
