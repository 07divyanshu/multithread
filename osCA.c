#include<pthread.h>
#include<stdio.h>

void *th_function1();
void *th_function2();
void *th_function3();
int sum=0;
int arr={23,12,45,13,55};
int bcc={23,12,45,13,55};
int d=bcc[0];
int m=ccd[0];
int ccd={23,12,45,13,55};
pthread_mutex_t lock;
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
    
    printf("average of arr is %d\n",sum);
    printf("maximum of bcc is %d\n",d);
    printf("minimum of ccd is %d\n",m);
}
void *th_function1()
{
    int i;
	pthread_mutex_lock(&lock);
	for(i=0;i<len(arr);i++)
	{
	  sum=sum+arr[i];
    }
	sum=sum/len(arr);
pthread_mutex_unlock(&lock);
}
void *th_function2()
{
	pthread_mutex_lock(&lock);
	for(int i=0;i<5;i++)
	{	if(d<bcc[i])
		{	d=bcc[i];
		}	
	}
pthread_mutex_unlock(&lock);
}
void *th_function3()
{
	pthread_mutex_lock(&lock);
	for(int i=0;i<5;i++)
	{	if(m>ccd[i])
		{	m=ccd[i];
		}	
	}
pthread_mutex_unlock(&lock);
}
