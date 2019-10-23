/*
	Objective : WAP to copy a source file into the target file and display the target file using system calls.
*/
#include<iostream>
#include<fcntl.h>	// creat(), open() system calls
#include<unistd.h>	// close(), read(), write() system calls
#include<stdlib.h>
using namespace std;
int main(int argc, char *argv[]){
	if(argc != 3){
		cout<<"File not found...\n";
		exit(1);
	}
	int fd1 = open(argv[1],0);
	if(fd1<0){
		cout<<"Error in opening file..."<<argv[1]<<endl;
		exit(2);
	}
	int fd2 = creat(argv[2],0666);
	if(fd2<0){
		cout<<"Error in creating file..."<<argv[2]<<endl;
		exit(3);
	}
	char buf[500];
	int count;
	while(count=read(fd1,buf,sizeof(buf))){
		write(fd2, buf, count);
	}
	close(fd1);
	close(fd2);
	return 0;
}

