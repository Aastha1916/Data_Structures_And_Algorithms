//array product
#include<stdio.h>
int main()
{
	int n,i,product=1;
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
    	product = product*a[i]; 
	}
	printf("Product of the array elements is %d",product);
}
