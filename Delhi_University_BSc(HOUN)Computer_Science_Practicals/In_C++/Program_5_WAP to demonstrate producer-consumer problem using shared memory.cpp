// Objective : WAP to demonstrate producer-consumer problem using shared memory.
#include<iostream>
#include<conio.h>
using namespace std;
template<class T>class CQueue{
	public:
		T *arr;
		int size, front, rear;
	public:
		CQueue(){
			size = 0;
			arr = new int[size];
			front = -1;
			rear = -1;
		}
		CQueue(int s){
			size = s;
			arr = new int[size];
			front = -1;
			rear = -1;
		}
		bool isEmpty(){
			return rear == -1;
		}
		bool isFull(){
			return (rear + 1) % size == front;
		}
		void enqueue(T x){
			if(isFull()){
				cout<<"Queue is full...\n";
				return;
			}
			else if(rear == -1){
				rear = 0;
				front = 0;
				arr[rear] = x;
			}
			else{
				rear = (rear + 1)% size;
				arr[rear] = x;
			}
		}
		void dequeue(){
			if(isEmpty()){
				cout<<"Queue is empty...\n";
				return;
			}
			else if(rear == front){
				T temp = arr[front];
				front = -1;rear = -1;
				cout<<"Deleted element : "<<temp<<endl;
				return;
			}
			else{
				T temp = arr[front];
				front = (front + 1)%size;
				cout<<"Deleted element : "<<temp<<endl;
				return;
			}
		}
		void peek(){
			if(isEmpty()){
				cout<<"Queue is empty...\n";
				return;
			}
			cout<<"Element at the top : "<<arr[front]<<endl;
		}
		void clear(){
			while(!isEmpty()){
				dequeue();
			}
		}
		void display(){
			if(isEmpty()){
				cout<<"Queue is empty...\n";
				return;
			}
			else if(rear >= front){
				cout<<"Elements in the circular queue are : "; 
	            for(int i = front; i < rear + 1; i++){
	            	cout<<arr[i]<<" ";
				}cout<<endl;
			} 
            
        	else{
        		cout<<"Elements in Circular Queue are : "; 
	            for(int i = front; i < size; i++){
	            	cout<<arr[i]<<" ";
				}cout<<endl;
	            for(int i = 0; i < rear + 1; i++){
	            	cout<<arr[i]<<" ";
				}cout<<endl;
			}
		}
		void menu(){
			char ch ='y';int op;
			do{
				cout<<"Enter Operation number to perform ::\n";
				cout<<"1.Enqueue\n2.Dequeue\n3.Peek\n4.Clear\n5.Display\n";
				cin>>op;
				switch(op){
					case 1:{
						T data;
						cout<<"Enter data : ";
						cin>>data;
						enqueue(data);
						break;
					}
					case 2:{						
						dequeue();
						break;
					}
					case 3:{
						peek();
						break;
					}
					case 4:{
						clear();
						break;
					}
					case 5:{
						display();
						break;
					}
					default:{
						cout<<"Invalid Input!!!\n";
						break;
					}
				}
				cout<<"Do you want to continue?(y/n) : ";
				cin>>ch;
			}while(ch=='y'||ch=='Y');
		}
};
int main(){
	int s;
	cout<<"Enter the size of queue : ";
	cin>>s;
	CQueue<int>obj(s);
	obj.menu();
	getch();
	return 0;
}

