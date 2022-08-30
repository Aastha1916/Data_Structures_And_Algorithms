#include<stdio.h>
int swap(int a[],int s1,int s2)
{
	int temp= a[s1];
	a[s1] =a[s2];
	a[s2]= temp;
}
int partition(int a[],int l,int h)
{
	int pivot= a[l];
	int start= l;
	int end = h;
	while(start<end)
	{
		while(a[start]<=pivot)
		start++;
		while(a[end]>pivot)
		end--;
		if(start<end)
		swap(a,start,end);
	}
	swap(a,end,l);
	return end;
}
int quicksort(int a[],int l,int h)
{
	if(l<h)
	{
		int pivot = partition(a,l,h);
		quicksort(a,l,pivot-1);
		quicksort(a,pivot+1,h);
	}
}
int main()
{
	int a[]={2,6,7,5,1,7,9,15,10};
	int n=sizeof (a)/sizeof (a[0]);
	int l=0;
	int h=n-1;
	quicksort(a,l,h);
	int i;
	for(i=0;i<n;i++)
	{
	printf(" %d ",a[i]);
	}
	return 0;
	
	
}
