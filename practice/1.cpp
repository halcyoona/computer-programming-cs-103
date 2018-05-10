#include<iostream>
#include<string>
using namespace std;

class test
{
	private: 
		//static int a;
		int b;
		int c;
	public:
		static int a;
		test(int a, int b, int c);
		static void fun();
		void print();
};



int test:: a = 4;
test::test(int a = 0, int b = 0, int c = 0)
{
	a = a;
	b = b;
	c = c;
}
void test::print()
{
	cout<<a<<" "<<b<<" " <<c<<endl;
}

void test::fun()
{
	a = a++;
	return ; 
}

int main()
{
	test t1;
	t1.a = 10;
	cout<<test::a<<endl;
	t1.print();
	//int d, a = 2, b = 5, c = 0;
	test::fun();
	//cout<<d<<c<<b<<a<<endl;
	return 0;
}
