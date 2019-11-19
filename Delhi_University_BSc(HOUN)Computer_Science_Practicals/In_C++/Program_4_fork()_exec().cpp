
// Program 4
/*
Objective : WAP (using fork() and/or exec() commands) where parent and child execute:
	a. same program, same code
	b. same program, different code
	c. different programs
	d. before terminating, the parent waits for the child to finish its task
*/

#include<iostream>
#include<sys/types.h>
/*
pid_t : Used for process IDs and process group IDs.
pthread_attr_t : Used to identify a thread attribute object.
pthread_t  :   Used to identify a thread.
*/
#include<unistd.h>
/*
#include<unistd.h> is the C/C++ header file that is your code's entry point to various constant, type and function declarations that comprise the POSIX operating system API. #include <unistd.h> gets you, among other things:

    [*] the infamous NULL pointer definition
    [*] pipe()
    [*] type definitions like size_t (which are often declared in other files, but unistd.h gets them for you)
    [*] function definitions like gethostname() and fork()
*/
using namespace std;
int main(){
	
	// [a]
	
	pid_t pid,p;
    p=fork();
    pid=getpid();
	if(p < 0)
	{
        fprintf(stderr,"Fork Failed");
		return 1;
	}
    printf("Output of Fork id: %d \n",p);
    printf("process id is:%d \n",pid);
    
    // [b]
    
    pid_t pid;
	// fork a child process
	pid = fork();
    if (pid < 0)
    {
		fprintf(stderr, "Fork Failed");
        return 1;
    }
    else if (pid == 0)
    {
		// child process
		execlp("/bin/ls","ls",NULL);
    }
    else
    {
        printf("Parent Process.");
    }
    
    // [c]
    
    pid_t pid;
	pid=fork();
	if(pid<0)
	{
		cout<<"No process entered";
	}
	else if(pid==0)
	{
		execlp("/bin/ls","ls",NULL);
		cout<<"child process";
	}
	else
	{
		cout<<"parent process";
	}
	
	// [d]
	
	pid_t pid;
	// fork a child process
	pid = fork();
    if (pid < 0)
    {
		fprintf(stderr, "Fork Failed");
        return 1;
    }
    else if (pid == 0)
    {
		// child process
		execlp("/bin/ls","ls",NULL);
    }
    else
    {
		// parent process
		// parent will wait for the child to complete
		wait(NULL);
        printf("Child Complete");
    }
    
	return 0;
}

