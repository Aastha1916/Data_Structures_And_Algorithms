//Linear search using recursive function
#include<stdio.h>

int linear_search(int arr[],int n,int key)
{
	int temp;
	n--;
	if (n>=0)
	{
		if (arr[n]==key)
		{
			return n;
		}
		else
		{
			temp=linear_search(arr,n,key);
		}
	}
	else{
		return -1;
	}
	
 }
 
 int main()
 {
 	int arr[]={12,34,54,67,89,3,45};
 	int n=sizeof(arr)/sizeof(arr[0]);
 	int key=3;
 	int index;
	index=linear_search(arr,n,key);
 	if (index!=-1)
 	{
 		printf("Element found at %d position",index+1);
	}
	else
	{
		printf("Element not found");
	}
	return 0;
 }
