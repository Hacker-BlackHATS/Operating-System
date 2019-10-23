/*
	Objective : WAP to print file details including owner access permissions,file access time, where file name is given as a command line 			    argument.
*/
#include<iostream>
#include<fcntl.h>	// File Control - Open, Retrive, Change file access Permissions
#include<stdlib.h>
#include<stdio.h>
#include<time.h>	// For Time
#include<sys/stat.h>	// This header shall define the structue of the data returned
//							by the functions fstat(), lstat() and stat() - File attributes
using namespace std;
int main(int argc, char*argv[]){
	char MY_TIME[50];
	struct stat s1;
	int fd;
	if(argc != 2){
		printf("Wrong number of arguments!!\n");
	}
	fd = open(argv[1],O_RDONLY);
	fstat(fd, &s1);
	cout<<"Owner ID : "<<s1.st_uid<<endl;
	cout<<"Group ID : "<<s1.st_gid<<endl;
	cout<<"Access Permissions : "<<s1.st_mode<<endl;
	cout<<"Size : "<<s1.st_size<<endl;
	cout<<"Number of links : "<<s1.st_nlink<<endl;
	strftime(MY_TIME, sizeof(MY_TIME),"%d.%m.%y %H.%M.%S",localtime(&s1.st_atime));
	cout<<"Last Access Time : "<<MY_TIME<<endl;
	strftime(MY_TIME, sizeof(MY_TIME),"%d.%m.%y %H.%M.%S",localtime(&s1.st_mtime));
	cout<<"Last Modified Time : "<<MY_TIME<<endl;
	return 0;
}

