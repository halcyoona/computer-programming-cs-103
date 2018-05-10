#include<iostream>
using namespace std;



void fun(int *a)
{
	cout<<*a<<endl;
	cout<<a[1]<<endl;
	cout<<*(a+2)<<endl;
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swapv(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int arr[3] = {2,4,6};
	int *ar = new int[3];
	for(int i = 0; i<3; i++)
	{
		*(ar+i) = i;
	}
	
	fun(arr);
	fun(ar);
	int *a = new int;
	int *b = new int;
	*a = 10;
	*b = 20;
	int c = 100;
	int d = 200;
	//swap(a, b);
	//swap(&c, &d);
	//swapv(c,d);
	swapv(*a,*b);
	//cout<<c<<endl;
	//cout<<d<<endl;
	cout<<*a<<endl;
	cout<<*b<<endl;
	delete [] ar;
	delete a;
	delete b;
	return 0;
}
