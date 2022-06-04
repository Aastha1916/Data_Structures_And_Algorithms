//to find second minimum elements in an array
#include<stdio.h>
int main()
{
	int i,j,n,index=0;
	printf("enter number of elemnts:\n");
	scanf("%d",&n);
	int a[n];
	
	printf("enter elemnts:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
    }
    int min=a[0],min1=a[1];
	for(i=0;i<n;i++)
	{
		if(min>a[i])
		{
		min=a[i];
		index=i;
	    }
	}
    for(j=0;j<n;j++)
	{
		if(j!=index)
		{
			if(min1>a[j])
			min1=a[j];
		}
	}
	printf("second minnimum element is %d",min1);
}
