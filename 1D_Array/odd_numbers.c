//remove even integers
#include<stdio.h>
int main()
{
	int i,j=0,n;
	printf("enter number of elemnts:\n");
	scanf("%d",&n);
	int a[n],b[n];
	printf("enter elemnts:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		if(a[i]%2!=0)
		{
			b[j]=a[i];
			j++;
		}
	}
	printf("elements left after removing even integers are:\n");
	for(i=0;i<j;i++)
	{
		a[i]=b[i];
		printf("%d\n",a[i]);
	}
	
}
