//array sum
#include<stdio.h>
int main()
{
	int n,i,sum=0;
	printf("Enter number of elements:\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter elements of your array:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
    	sum=sum+a[i];
	}
	printf("Sum of the array is %d",sum);
}

