#include<iostream>
using namespace std;

class checking
{
	protected:
		static int i;
	public:
		static int total;
		checking();
		~checking();
		void print();
		static void showtotal();
};

int checking:: total = 0;
int checking:: i = 0;
checking::checking()
{
	i++;
}
checking::~checking()
{
	i--;
}

void checking::print()
{
	cout<<"value : "<<i<<endl;
	total++;
}

void checking::showtotal()
{
	cout<<"show = "<<total<<endl;
}

int main()
{
	checking c1,c2,c3;
	cout<<c1.total<<endl;
	c1.print();
	c2.print();
	cout<<checking::total<<endl;
	checking::showtotal();
	cout<<c1.total<<endl;
	c3.print();
	return 0;
}
