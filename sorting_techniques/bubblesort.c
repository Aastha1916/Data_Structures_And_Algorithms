#include<stdio.h>
int Bubble(int a[],int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
			temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
		    }
		}
	}
}
int main()
{
	int a[5]={18,35,32,13,26};
	int n=sizeof (a)/sizeof (a[0]);
	printf("before sorting array elements are-\n");
	int i;
	for(i=0;i<n;i++)
	{
		printf(" %d ",a[i]);
	}
	Bubble(a,n);
	printf("\nafter sorting array elements are-\n");
	for(i=0;i<n;i++)
	{
		printf(" %d ",a[i]);
	}
	return 0;
}


