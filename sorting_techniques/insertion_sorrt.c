#include<stdio.h>
void insertion_sort(int a[],int n)
{
	int i,j,key;
	for(i=1;i<n;i++)
	{
		key=a[i];
		j=i-1;
		while(j>=0 && a[j]>key)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
}
void print_array(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf(" %d ",a[i]);
	}
}
int main()
{
	int n,i;
	printf("enter number of elements:");
	scanf("%d",&n);
	int a[n];
	printf("enter elements in the array:");
	for (i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	insertion_sort(a,n);
	printf("array after sorting :");
	print_array(a,n);
	return 0;
}

