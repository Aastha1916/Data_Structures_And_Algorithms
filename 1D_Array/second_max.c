//to find second maximum elements in an array
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
    int max=a[0],max1=a[1];
	for(i=0;i<n;i++)
	{
		if(max<a[i])
		{
		max=a[i];
		index=i;
	    }
	}
    for(j=0;j<n;j++)
	{
		if(j!=index)
		{
			if(max1<a[j])
			max1=a[j];
		}
	}
	printf("second maximum element is %d",max1);
}
