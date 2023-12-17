#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include<pthread.h>
#include<time.h>

void * roll_dice ()
{
    int value = (rand() %6 )+1;
    printf("value: %d\n",value); 
    printf("start thread  \n");
    sleep(2);
    printf("end thread \n");
}


int main(int argc, char const *argv[])
{
    srand(time(NULL)); 
    pthread_t t1; 
    pthread_create(&t1, NULL,&roll_dice,NULL);
    pthread_join(t1,NULL); // the second argument is for getting the result of the roll_dice 
    return 0;
}
