#include<stdio.h>
int main()
{
	int n,i,j,max,m,count=0,k=0;
	printf("enter number of elemnts:\n");
	scanf("%d",&n);
	int a[n];
	printf("enter elements of the given array:\n");
	for (i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	max=a[0];
	for (i=0;i<n;i++)
	{
		if(max<a[i])
		max=a[i];
	}
	m=max+1;
	int b[m];
	for (i=0;i<m;i++){
	b[i]=0;}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if (a[i]==j)
			{
			b[j]++;
			break;
			}
		}
	}
	int c[n];
	for(i=0;i<m;i++)
	{
	
		while(b[i]!=0)
		{
			c[k]=i;
			b[i]--;
			k++;
		}
	}
	printf("sorted count array:");
	for(i=0;i<k;i++)
	{
		printf(" %d ",c[i]);
	}
}
