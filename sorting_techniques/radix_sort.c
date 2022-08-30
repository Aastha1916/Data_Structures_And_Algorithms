// radix sort
#include<stdio.h>
int getmax(int a[],int n)
{
	int max=a[0];
	int i;
	for (i=0;i<n;i++)
	{
		if (a[i]>=max)
		{
			max=a[i];
		}
	}
	return max;
}
void countsort(int a[],int n,int pos)
{
	int count[10]={0};
	int i,b[n];
	for (i=0;i<n;i++)
	{
		++count[a[i]%(10*pos)];
	}
	for (i=0;i<n;i++)
	{
		count[i+1]=count[i]+count[i+1];
	}
	for (i=n-1;i>=0;i--)
	{
		b[--count[a[i]%(10*pos)]]=a[i];
	}
	for (i=0;i<n;i++)
	{
		a[i]=b[i];
	}
}
void radixsort(int a[],int n)
{
	int max =getmax(a,n);
	int pos;
	for (pos=1;max/pos>0;pos*10)
	{
		countsort(a,n,pos);
	}
}

int main()
{
	int a[]={100,9,65,78,3,66,98,776,113};
	int n=sizeof (a)/sizeof (a[0]);
	int i;
	radixsort(a,n);
	for (i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}











