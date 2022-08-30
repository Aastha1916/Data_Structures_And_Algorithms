//to find minimum elements in an array
#include<stdio.h>
int main()
{
	int i,j,n;
	printf("enter number of elemnts:\n");
	scanf("%d",&n);
	int a[n];
	
	printf("enter elemnts:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
    }
    int min=a[0],max=a[1];
	for(i=0;i<n;i++)
	{
		if(min>a[i])
		min=a[i];
	}
    printf("\n minimum number = %d\n",min);
    for(i=0;i<n;i++)
	{
		if(max<a[i])
		max=a[i];
	}
	printf("\n maximum number = %d\n",max);
}
