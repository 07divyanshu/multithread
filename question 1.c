#include<pthread.h>
#include<stdio.h>

void *th_function1();
void *th_function2();
void *th_function3();
int i,n;
int arr1[20];

pthread_mutex_t lock;
int minimum,maximum;
float sum=0.0;

int main()
{
	printf("how many element you want to enter");
	scanf("%d",&n);
for(i=0;i<n;i++)
{
	printf("Enter the value");
	scanf("%d",&arr1[i]);
}
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
	pthread_mutex_lock(&lock);
	for(i=0;i<n;i++)
	{
	  sum=sum+arr1[i];
    }
	sum=sum/5;
	pthread_mutex_unlock(&lock);
}
void *th_function2()
{
	pthread_mutex_lock(&lock);
	minimum=arr1[0];
	for(i=0;i<n;i++)
	{	
		if(arr1[i]<minimum)
		{	
			minimum=arr1[i];
		}	
	}
	
	pthread_mutex_unlock(&lock);
}
void *th_function3()
{
	pthread_mutex_lock(&lock);
	maximum=arr1[0];
	for(i=0;i<n;i++)
	{	if(arr1[i]>maximum)
		{	
			maximum=arr1[i];
		}	
	}
pthread_mutex_unlock(&lock);
}
