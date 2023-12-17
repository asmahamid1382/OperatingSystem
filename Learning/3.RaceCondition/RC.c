#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int mails = 0;

void *Function()
{
    for (int i = 0; i < 1000000; i++)
    {
        mails++;
        /// read the value
        /// increment
        ///  write back to memmory
    }
}

int main(int argc, char const *argv[])
{
    pthread_t t1, t2;
    pthread_create(&t1, NULL, &Function, NULL);
    pthread_create(&t2, NULL, &Function, NULL);
    pthread_join(t1, NULL); // the second argument is for getting the result of the function
    pthread_join(t2, NULL);
    printf("number of mails:%d\n", mails);
    return 0;
}
