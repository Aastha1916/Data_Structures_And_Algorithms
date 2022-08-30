//merge two sorted arrays
#include<stdio.h>
int main()
{
	int n,m,i=0,j=0,k=0;
	printf("enter number of elements in array 1:\n");
	scanf("%d",&n);
	printf("enter number of elements in array 2:\n");
	scanf("%d",&m);
	int a[n],b[m],c[n+m];
	printf("enter elements of array 1 in sorted format:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d ",&a[i]);
	}
	printf("enter elements of array 2 in sorted format:\n");
	for(j=0;j<m;j++)
	{
		scanf("%d ",&b[j]);
	}
	if(i<n&&j<m)
	{
		if(a[i]<b[j])
		{
			c[k]=a[i];
			i++;
			k++;
		}
		else
		{
			c[k]=b[j];
			j++;
			k++;
		}
	}
	if(i>=n)
	{
		while(j<m)
		{
			c[k]=b[j];
			k++;
			j++;
		}
	}
	if(j>=m)
	{
		while(i<n)
		{
			c[k]=a[i];
			k++;
			i++;
		}
	}
	printf("merged array:\n");
	for(i=0;i<k;i++)
	{
		printf("%d ",c[i]);
	}
}







