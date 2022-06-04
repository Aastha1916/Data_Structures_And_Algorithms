//To find second minimum elements in an array
#include<stdio.h>
int main()
{
	int i,j,n,index=0;
	printf("Enter number of elements:\n");
	scanf("%d",&n);
	int a[n];
	
	printf("Enter elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
    }
    int min=a[0],min1=a[1];
	for(i=0;i<n;i++)   //Finding minimum element
	{
		if(min>a[i])
		{
		min=a[i];
		index=i;
	    }
	}
    for(j=0;j<n;j++)	//Finding second minimum element
	{
		if(j!=index)
		{
			if(min1>a[j])
			min1=a[j];
		}
	}
	printf("Second minimum element is %d",min1);
}
