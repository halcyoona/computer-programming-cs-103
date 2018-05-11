#include<iostream>
using namespace std;

class stack 
{
	protected:
		int size;
		int *arr;
		int top;
	public:
		stack(int s);
		~stack();
		void insert(int num);
		void del();
		void display();
};


stack::stack(int s = 0;)
{
	size = s;
	top = -1;
	arr = new int[size];
}

stack::~stack()
{
	size = 0;
	top = 0;
	delete [] arr;
}



void stack::insert(int num)
{
	if(size > 0)
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
	else
	{
		cout<<"declare the size of the stack:"<<endl;
	}
}

void stack::del()
{
	if(size > 0)
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
	else
	{
		cout<<"declare the size of the stack:"<<endl;
	}
}

void stack::display()
{
	if(size > 0)
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
	else
	{
		cout<<"declare the size of the stack:"<<endl;
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


