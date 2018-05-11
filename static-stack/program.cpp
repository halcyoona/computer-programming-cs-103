#include<iostream>
using namespace std;

class stack 
{
	protected:
		int size;
		int arr[5];
		int top;
	public:
		stack();
		~stack();
		void insert(int num);
		void del();
		void display();
};


stack::stack()
{
	size = 5;
	top = -1;
	for(int i = 0; i < 0; i++)
	{
		arr[i] = 0;
	}
}

stack::~stack()
{
	size = 0;
	top = 0;
	for(int i = 0; i < 0; i++)
	{
		arr[i] = 0;
	}
}



void stack::insert(int num)
{
	if(top == size -1)
	{
		cout<<"Stack is full"<<endl;
		return;
	}
	else if(top == -1)
	{
		top = 0;
	}
	else
	{
		top += 1;
	}
	arr[top] = num;
}

void stack::del()
{
	if(top == -1)
	{
		cout<<"Stack is empty"<<endl;
		return ;
	}
	else
	{
		top -= 1;
	}
}

void stack::display()
{
	if(top != -1)
	{
		for(int i =0; i <= top; i++)
		{
			cout<<"Element "<<i+1<<" : "<<arr[i]<<endl;
		}
	}
	else
	{
		cout<<"stack is empty:"<<endl;
		return ;
	}
}

int main()
{
	stack s;
	s.insert(2);
	s.insert(4);
	s.insert(6);
	s.insert(8);
	s.insert(10);
	//s.insert(12);
	s.display();
	s.del();
	s.del();
	s.del();
	s.del();
	s.insert(24);
	s.display();
	return 0;
}


