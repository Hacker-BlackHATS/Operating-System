/*
	Objective : WAP to display the following:
		a. Kernel Version
		b. CPU type and model
		c. Information on Configured memory, amount of free and used memory
*/
#include<iostream>
#include<stdio.h>
#include<sys/vfs.h>	// File system info
#include<sys/sysinfo.h>	// Memory info
#include<sys/utsname.h>	// Kernel info
using namespace std;
//  (FOR LINUX)
class Linux{
	private:
		int r, MB, p, q, GB;
		struct sysinfo s1; struct utsname s2; struct statfs s3;
	public:
		Linux(){
			r = sysinfo(&s1);
			q = uname(&s2);
			p = statfs("/",&s3);
			MB = (1024*1024);
			GB = (MB*1024);
		}
		void Display(){
			if(r==0&&q==0&&p==0){
				printf("\n System name : %s",s2.sysname);
				printf("\n Kernel version : %s",s2.version);
				printf("\n Release : %s",s2.release);
				printf("\n Machine : %s",s2.machine);
				printf("\n Total Ram : %ldMB",(s1.totalram/MB));
				printf("\n Free Ram : %ldMB",(s1.freeram/MB));
				printf("\n Used Ram : %ldMB",((s1.totalram-s1.freeram)/MB));
				printf("\n Total size of partition : %ldGB",(s3.f_bsize+s3.f_blocks)/GB);
			}
			else{
				printf("Error!!!\n");
			}
		}
};
int main(){
	Linux obj;
	obj.Display();
	return 0;
}

