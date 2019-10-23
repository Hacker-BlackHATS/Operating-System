// Objective : Implement Producer-Consumer problem using POSIX Shared Memory API
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include<conio.h>
using namespace std;
class POSIX_Shared_Memory_PC{
	private:
		const int SIZE;
		const char*name;
		int shm_fd;		// Shared Memory file descriptor
		void *ptr;		// Pointer to shared memory object
	public:
		POSIX_Shared_Memory_PC(){
			SIZE = 4096;	// Size of Shared memory object
			name = "OS";	// Name of shared memory object
		}
		void Producer(){
			// String written to shared memory
			const char *message_0 = "Hello";
			const char *message_1 = "World";
			// Create the shared memory object
			shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
			// Configure the size of the shared memory object
			ftruncate(shm_fd, SIZE);
			// Memory map the shared memory object
			ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED,shm_fd, 0);
			// Write to shared memory object
			sprintf(ptr,"%s",message_0);
			ptr += strlen(message_0);
			sprintf(ptr,"%s",message_1);
			ptr += strlen(message_1);
		}
		void Consumer(){
			shm_fd = shm_open(name, O_RDONLY, 0666);
			ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED,shm_fd, 0);
			// Read from the shared memory object
			printf("%s",(char*)ptr);
			// Remove the shared memory object
			shm_unlike(name);
		}
};
int main(){
	POSIX_Shared_Memory_PC obj;
	obj.Producer();
	obj.Consumer();
	getch();
	return 0;
}

