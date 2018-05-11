#include<iostream>
using namespace std;

class queue
{
	protected:
		int size;
		int *arr;
		int front;
		int rear;
	public:
		queue(int s);
		~queue();
		void insert(int num);
		void del();
		void display();
};

queue::queue(int s = 0)
{
	front = -1;
	rear = -1;
	size = s;
	arr = new int [size];
	for(int i = 0; i < size; i++)
	{
		arr[i] = 0;
	}
}

queue::~queue()
{
	front = 0;
	rear = 0;
	size = 0;
	delete [] arr;
}

void queue::insert(int num)
{
	if (size > 0)
	{
		if((rear == size-1 && front == 0)||(front == rear + 1))
		{
			cout<<"Queue is overflow"<<endl;
			return;
		}
		else if(front == -1 && rear == -1)
		{
			front = 0;
			rear = 0;
		}
		else if(front != 0 && rear == size-1)
		{
			rear = 0;
		}
		else
		{
			rear += 1;
		}
		arr[rear] = num;
	}
	else
	{
		cout<<"Declare the size of the array:"<<endl;
	}
}

void queue::display()
{
	if(size > 0)
	{
		if (rear > front)
		{
			for(int i = front ; i <= rear; i++)
			{
				cout<<"element "<<i+1<<" : "<<arr[i]<<endl;
			}
		}
		else if(front > rear)
		{
			for(int i = front; i < size; i++)
			{
				cout<<"element "<<i+1<<" : "<<arr[i]<<endl;
			}
			for(int i = 0; i <= rear; i++)
			{
				cout<<"element "<<i+1<<" : "<<arr[i]<<endl;
			}
		}
		else
		{
			cout<<"Queue is empty"<<endl;
		}
	}
	else
	{	
		cout<<"Declare the size of the array:"<<endl;
		return;	
	}
}

void queue::del()
{
	if(size > 0)
	{
		if(front== -1)
		{
			cout<<"underflow"<<endl;
		}
		else if(front == rear)
		{
			front = -1;
			rear = -1;
		}
		else
		{	
			if(front == size -1)
			{
				front = 0;
			}
			else
			{
				front += 1;
			}
		}
	}
	else
	{	
		cout<<"Declare the size of the array:"<<endl;
		return;	
	}
}



int main()
{
	queue q(5);
	q.insert(2);
	q.insert(3);
	q.insert(4);
	q.insert(5);
	q.insert(6);
	q.display();
	q.del();
	q.del();
	q.del();
	q.del();
	q.del();
	q.display();
	q.insert(12);
	q.insert(13);
	q.insert(14);
	q.insert(15);
	q.insert(16);
	//q.del();
	q.display();
	return 0;
}
