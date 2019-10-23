// Objective : Windows Multi-Threading Program
#include<iostream>
#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<unistd.h>
using namespace std;
DWORD sum1,sum2;
DWORD WINAPI tfun1(LPVOID Param){
	for(DWORD i = 0; i< 8;i++){
		sleep(1);
		printf("Function 1\n");
	}
	return 0;
}
void tfun2(){
	for(DWORD i = 0; i< 2;i++){
		sleep(2);
		printf("Function 2\n");
	}
}
int main(){
	
	HANDLE harr;
	DWORD ThreadID1;
	harr = CreateThread(NULL,0,tfun1,NULL,0,&ThreadID1);
//	harr[1] = CreateThread(NULL,0,tfun2,&b,0,&ThreadID2);
//	if(harr == NULL){
//		cout<<"Error in thread creationand error no. ---> "<<GetLastError()<<endl;
//	}
	tfun2();
	//WaitForMultipleObjects(2,harr,TRUE,INFINITE);
	//WaitForSingleObject(harr[0],INFINITE);
//	cout<<"Thread-1 ID : "<<ThreadID1<<endl;
//	cout<<"Thread-2 ID : "<<ThreadID2<<endl;
//	CloseHandle(harr);
//	cout<<"Thread-1 Sum = "<<sum1<<endl;
//	cout<<"Thread-2 Sum = "<<sum2<<endl;
	getch();
	return 0;
}

