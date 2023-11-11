#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int count = 0;

void *PrintHello(void *arg)
{
	int i, re = *(int*)arg;
	for (i = 1; i <= 25000000; i++)
		count += 1;
	printf("Thread ID:%lu complete, count:%d\n", pthread_self(), count);
	pthread_exit((void*)re);
}

int main()
{
	pthread_t thread1, thread2, thread3, thread4;
	int rc, t = 0;
	void *ret;

	rc = pthread_create(&thread1, NULL, PrintHello, &t);
	rc = pthread_create(&thread2, NULL, PrintHello, &t);
	rc = pthread_create(&thread3, NULL, PrintHello, &t);
	rc = pthread_create(&thread4, NULL, PrintHello, &t);
	if (rc){
		printf("create error\n");
		exit(-1);
	}

	rc = pthread_join(thread1, &ret);
	rc = pthread_join(thread2, &ret);
	rc = pthread_join(thread3, &ret);
	rc = pthread_join(thread4, &ret);
	if (rc){
		printf("join error\n");
		exit(-1);
	}
	
	printf("total count:%d\n", count);
	return 0;
}
