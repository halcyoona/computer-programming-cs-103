#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

class linklist
{
	protected:
		Node *head;
		Node *tail;
	public:
		linklist();
		~linklist();
		void addInTheEnd(int info);
		void addInTheStart(int info);
		void del(int info);
		void display();
};


linklist::linklist()
{
	head = NULL;
	tail = NULL;
}

linklist::~linklist()
{
	Node *p;
	Node *q;
	q = head;
	while(q != NULL)
	{
		p = q;
		q = q->next;
		delete p;
	}
}

void linklist::addInTheStart(int info)
{
	Node *temp = new Node;
	temp->data = info;
	temp->next = NULL;
	if(head == NULL)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		temp->next = head;
		head = temp;
	}
	
}


void linklist::addInTheEnd(int info)
{
	Node *temp = new Node;
	temp->data = info;
	temp->next = NULL;
	if(head == NULL)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
	
}

void linklist::display()
{
	if(head==NULL)
	{
		cout<<"linklist is empty"<<endl;
	}
	else
	{
		int i = 1;
		Node *temp;
		temp = head;
		while(temp != NULL)
		{
			cout<<i<<" : "<<temp->data<<endl;
			temp = temp->next;
			i++;
		}
	}
}

void linklist::del(int info)
{
	if(head==NULL)
	{
		cout<<"linklist is empty"<<endl;
	}
	else if(head == tail)
	{
		if(head->data == info)
		{
			delete head;
		}
		else
		{
			cout<<info<<endl;
			cout<<"There is no Node with this data"<<endl;
		}
	}
	else
	{
		Node *q;
		Node *p;
		q = head;		
		if(head->data == info)
		{
			head = head->next;
			delete q;
		}
		else
		{
			while(q != NULL)
			{
				if(q->data == info)
				{
					p->next = q->next;
					delete q;
					return;
				}
				else if(q == tail)
				{
					tail = p;
					delete q;
				}
				else
				{
					p = q;
					q = q->next;
				}
			}
		}
	}
}


,

int main()
{

	linklist l;
	l.addInTheEnd(25);
	l.addInTheEnd(40);
	l.addInTheEnd(41);
	l.display();
	l.del(40);
	l.addInTheStart(12);
	l.addInTheEnd(24);
	l.del(25);
	l.del(24);
	l.display();
	return 0;
}
