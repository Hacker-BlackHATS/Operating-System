//	Objective : Write programs to understand working of Pthread library.
#include<iostream>
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int sum;
void*runner(void*param){
	int i , upper = *(int*)param;
	sum = 0;
	for(i = 1; i <= upper; i++){
		sum += i;
	}
	pthread_exit(0);
}
int main(){
	pthread_t tid;
	int a = 4;
	pthread_creat(&tid, NULL, runner,&a);
	pthread_join(tid, NULL);
	printf("Sum = %d",sum,"\n");
	return 0;
}

