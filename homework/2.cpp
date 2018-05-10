#include<iostream>
using namespace std;

class A
{
	public:
		static int a;
};
int A::a =10;


int main()
{
	cout<<A::a<<endl;
	return 0;
}
