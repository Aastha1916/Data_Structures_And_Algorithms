//Binary search technique is applicable for searching elements in sorted arrays only in O(log n) time complexity
#include<stdio.h>
int search_sorted(int a[],int key,int lb,int ub)
{
	int mid;
	mid=(ub+lb)/2;//calculating the middle index
	if(ub<lb)
	{
		printf("not valid\n");
		return -1;
	}
	else if(a[mid]==key)//checking if the middle element is the key element
	return mid;
	else if(a[mid]<key)//checking if the key element is smaller than middle element
	return search_sorted(a,key,mid+1,ub);//then search for element in left subarray 
	else
	return search_sorted(a,key,lb,mid-1);//if the key element is greater then the middle value then search in the right subarray
	
}
int main()
{
	int key,pos,i,index,n;
	//int a[]={ 2,55,1,34,99,4};
	//int n= sizeof (a)/sizeof (a[0]);
	printf("Enter the size of your Array:\n ");
	scanf("%d",&n);
	int lb=0; //initializing lower bound of the array
	int ub=n-1; //initializing upper bound of the array
	int a[n];
	printf("Enter elements of your sorted Array :\n ");
	for (i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Given array is:");
	for(i=0;i<n;i++)
	{
		printf(" %d ",a[i]);
	}
	printf("\nEnter the key element :\n");
	scanf("%d",&key);
	index=search_sorted(a,key,lb,ub);//calling function to search element
	pos=index+1;
	if (pos>0)
	printf("Element found at %d postition\n",pos);
	else
	printf("Element not found !!");
	return 0;
}
