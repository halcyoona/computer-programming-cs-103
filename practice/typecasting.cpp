#include<iostream>
using namespace std;

int main()
{
	cout<<"static_cast<int> = "<<static_cast<int>(25.0)<<endl;
	cout<<"static_cast<int> = "<<static_cast<int>(25.5)<<endl;
	cout<<"static_cast<long> = "<<static_cast<long>(23.5)<<endl;
	cout<<"static_cast<double> = "<<static_cast<double>(25)/2<<endl;
	cout<<"static_cast<float> = "<<static_cast<float>(23)/4<<endl;
	cout<<"static_cast<int> = "<<static_cast<int>('2')<<endl;
	cout<<"static_cast<char> = "<<static_cast<char>("A")<<endl;
	
	return 0;
}
