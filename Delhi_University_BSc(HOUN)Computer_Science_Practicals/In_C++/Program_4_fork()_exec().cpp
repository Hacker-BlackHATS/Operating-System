/*
	Objective : WAP (using fork() and/or exec() commands) where parent and child execute:
		    <.a.> same program, same code
		    <.b.> same program, different code
		    <.c.> different programs
		    <.d.> before terminating, the parent waits for the child to finish its task
*/
#include<iostream>
#include<sys/types.h>
#include<unistd.h>
using namespace std;
int main(){
	pid_t pid;
	pid=fork();
	cout<<"\1 pid is "<<pid<<endl;
	cout<<"1 get pid is "<<getpid()<<endl;
	if(pid<0){
		cout<<"\nThis is a process...\n";
		cout<<"2 pid is "<<pid<<endl;
		cout<<"2 pid is "<<getpid()<<endl;
	}
	else{
		cout<<"\nProcess continues...\n";
		cout<<"3 pid is "<<pid<<endl;
		cout<<"3 pid is "<<getpid()<<endl;
	}
	return 0;
}

