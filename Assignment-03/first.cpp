#include<iostream>
using namespace std;

////////////Loop and Recursion///////////


void sort(int arr[], int size, int index);

int main()
{
	int arr[10]={20,70,90,10,50,14,54,67,100,45};
	sort(arr,9,0);
	for(int i = 0; i < 10; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	return 0;	
}




void sort(int arr[], int size, int index)
{
	int i = index , j = size, counter = 1;
	while(i != j)
	{
		if (arr[i]>arr[j])
		{
			int temp;
			temp = *(arr+j);
			*(arr+j) = *(arr+i);
			*(arr+i) = temp;
			counter += 1;
			if (counter % 2 == 0)
			{
				j -= 1;
			}
			else
			{
				i += 1;
			}
		}
		else
		{
			if(counter % 2 == 0)
			{
				j -= 1;
			}
			else
			{
				i += 1;
			}
		}	
	}
	

	if (j==0 || j ==size)
	{
		return;
	}
	else
	{
		sort(arr,j-1,0);
		sort(arr, size, j+1);
		return;
	}

}
