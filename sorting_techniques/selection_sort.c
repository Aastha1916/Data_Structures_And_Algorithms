#include<stdio.h>
int swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void print(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf(" %d ",a[i]);
	}
}
void selection_sort(int a[],int n)
{
	int min_idx,i,j;
	for(i=0;i<n-1;i++)
	{
	   int min_idx=i;
	   for(j=i+1;j<n;j++)
	   {
	   if(a[min_idx]>a[j])
	   {
	     min_idx=j;
	     swap(&a[min_idx],&a[i]);
	   }
	   
       }
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
	selection_sort(a,n);
	printf("array after sorting :");
	print(a,n);
	return 0;
}

