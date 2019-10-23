/*
	Objective : WAP to demonstrate InterProcess Communication (IPC) between parent and child using pipe system call.
*/
#include<iostream>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>	// To gain access to the definition of _LP64 and _ILP32
#include<stdlib.h>
using namespace std;
int main(){
	pid_t pid;
	char msg[] = "Message Passing.";
	int msize = 30,p[2];
	int a = pipe(p);
	pid = fork();
	char buf[msize];
	if(pid < 0 || a < 0){
		cout<<"Error!!!\n";
		exit(0);
	}
	else if(pid == 0){
		read(p[0],buf,msize);
		cout<<"Buffer : "<<buf<<endl;
	}
	else if(pid > 0){
		write(p[1],msg,msize);
	}
	return 0;
}

