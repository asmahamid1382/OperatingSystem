#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include<pthread.h>
int primes[10]={2,3,5,7,11,13,17,19,23,29};
void* routine(void* args)
{
    int index = *(int*)args; 
    int sum =0 ; 
    for (int i = 0; i < 5; i++)
    {
       sum+=primes[index+i];
    } 
printf("local  Sum : %d\n",sum);
    *(int*)args=sum;

    return args; 


}
int main()
{
    pthread_t th[2]; 
    int finalsum=0; 
    for (int i = 0; i < 2; i++)
    {
        int* a = malloc(sizeof(int));
        *a=i*5;
        pthread_create(&th[i], NULL,&routine,a);
    }
    for (int i = 0; i < 2; i++)
    {
        int* result;
        pthread_join(th[i],&result);
        finalsum+=*result; 
        free(result); 
    }
    printf("Global Sum : %d\n",finalsum);

}