#include<stdio.h>
int main()
{   int n,m;
    printf("enter number of elements of first set A:");
	scanf("%d",&n);
	printf("enter number of elements of second set B:");
	scanf("%d",&m);
	int a[n],b[m],i,j;
	printf ("enter elements of first set A:");
	for(i=0;i<n;i++)
	{
	   scanf("%d",&a[i]);
    }
    printf ("enter elements of second set B:");
	for(i=0;i<m;i++)
	{
	   scanf("%d",&b[i]);
    }
    int c[m+n],l=n-1,k=0,t,flag=0;
    for(i=0;i<n;i++)
	{
    	c[k]=a[i];
    	k++;
	}
	for(j=0;j<m;j++)
	{
		flag=0;
		for(t=0;t<n;t++)
		{
		   if(b[j]==c[t])
			{ 
		       flag++;
		       break;
			}
			
		}
		
	if (flag==0)
	{
		c[k]=b[j];
		k++;
		}	
	}	

	printf ("union of set A and B is:");
	for(i=0;i<k;i++)
	{
	   printf("%d",c[i]);
    }
    printf("\n2001641520002_aastha_agarwal");
}



