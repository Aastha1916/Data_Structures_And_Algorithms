#include<stdio.h>
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void maxheapify(int A[],int n,int i)
{
	int largest=i;
	int l=2*i+1;
	int r=2*i+2;
	if (l<n && A[l]>A[largest])
	{
		largest=l;
	}
	if (r<n && A[r]>A[largest])
	{
		largest=r;
	}
	if (i!=largest)
	{
		swap(&A[i],&A[largest]);
		maxheapify(A,n,largest);
	}
}
void heapsort(int A[],int n)
{
	int i;
	//build maxheap
	for (i=n/2-1;i>=0;i--)
	{
		maxheapify(A,n,i);
	}
	//delete
	for (i=n-1;i>=0;i--)
	{
		swap(&A[i],&A[0]);
		maxheapify(A,i,0);
	}
}
void printArray(int A[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	}
}
int main()
{
	int A[]={1,12,9,5,6,10};
	int n=sizeof(A)/sizeof(A[0]);
	
	heapsort(A,n);
	
	printArray(A,n);
	return 0;
}
