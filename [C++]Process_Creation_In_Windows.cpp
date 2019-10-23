// Objective : Process Creation in Windows
#include<stdio.h>
#include<windows.h>
#include<conio.h>
using namespace std;
class Window_Process_Creation{
	private:
		STARTUPINFO si;
		PROCESS_INFORMATION pi;
	public:
		Window_Process_Creation(){
			ZeroMemory(&si,sizeof(si));
			si.cb = sizeof(si);
			ZeroMemory(&pi,sizeof(pi));
		}
		void Creation(){
			if(!CreateProcess(NULL,"C:\\Windows\\System32\\mspaint.exe",NULL,NULL,FALSE,0,NULL,NULL,&si,&pi)){
				fprintf(stderr,"Create Process Failed");
				return;
			}
			WaitForSingleObject(pi.hProcess,INFINITE);
			printf("Child Complete\n");
			CloseHandle(pi.hProcess);
			CloseHandle(pi.hThread);
		}
};
int main(){
	Window_Process_Creation obj;
	obj.Creation();
	getch();
	return 0;
}

