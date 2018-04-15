#include<pthread.h>
#include<stdio.h>

void *th_function1();
void *th_function2();
void *th_function3();

int arr1[5]={23,12,45,13,55};
int arr2[5]={23,12,45,13,55};
int arr3[5]={23,12,45,13,55};
pthread_mutex_t lock;
int minimum,maximum;
float sum=0.0;

int main()
{
	pthread_mutex_init(&lock,NULL);
	pthread_t thread1,thread2,thread3;
	pthread_create(&thread1,NULL,th_function1,NULL);
    pthread_create(&thread2,NULL,th_function2,NULL);
    pthread_create(&thread3,NULL,th_function3,NULL);
    
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    pthread_join(thread3,NULL);
    
    printf("average of arr1 is %.2f\n",sum);
    printf("minimum value from arr2 is %d\n",minimum);
    printf("maximum value from arr3 is %d\n",maximum);
    
}
void *th_function1()
{
    int i;
	for(i=0;i<5;i++)
	{
	  sum=sum+arr1[i];
    }
	sum=sum/5;
}
void *th_function2()
{
	int i;
	minimum=arr2[0];
	for(i=0;i<5;i++)
	{	
		if(arr2[i]<minimum)
		{	
			minimum=arr2[i];
		}	
	}
}
void *th_function3()
{
	int i;
	maximum=arr3[0];
	for(i=0;i<5;i++)
	{	if(arr3[i]>maximum)
		{	
			maximum=arr3[i];
		}	
	}
}
