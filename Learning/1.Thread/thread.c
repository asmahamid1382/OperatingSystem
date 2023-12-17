#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include<pthread.h>

void * Function ()
{
    printf("start thread  \n");
    sleep(2);
    printf("end thread \n");
}


int main(int argc, char const *argv[])
{
    pthread_t t1, t2  ; 
    pthread_create(&t1, NULL,&Function,NULL);
    pthread_create(&t2, NULL,&Function,NULL);
    pthread_join(t1,NULL); // the second argument is for getting the result of the function 
    pthread_join(t2,NULL);
    return 0;
}
