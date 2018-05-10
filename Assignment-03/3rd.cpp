#include<iostream>
using namespace std;

/////// Recursion////////////////

void sort(int arr[], int size, int index);
int fun(int arr[],int j, int i, int counter);

int main()
{
	int arr[]={20,70,90,10,50,24,56,777,99,87,14,54,67,100,45};
	sort(arr,14,0);
	for(int i = 0; i < 15; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	return 0;	
}




void sort(int arr[], int size, int index)
{
	int i = index , j = size, counter = 1;
	j = fun(arr, j, i, counter);
	

	if (j == 0 || j == size)
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


int fun(int arr[],int j, int i, int counter)
{
	if (j==i)
	{
		return j;
	}
	else
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
		return fun(arr, j, i, counter);	
	}			
}
