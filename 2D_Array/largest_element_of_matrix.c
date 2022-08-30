//to find the largest element in the matrix
#include<stdio.h>
int main()
{
	int r,c,i,j,k;
	printf("enter number of rows of given matrix :\n ");
	scanf("%d",&r);
	printf("enter number of columns of given matrix A:\n ");
	scanf("%d",&c);
	int a[r][c];
	printf("enter elements of first matrix A:\n");
	for (i=0;i<=r-1;i++)
	{
		for(j=0;j<=c-1;j++)
		{
			scanf("%d",&a[i][j]);
			
		}
	}
	int max=a[0][0];
	for (i=0;i<=r-1;i++)
	{
		for(j=0;j<=c-1;j++)
		{
		       if(max<a[i][j])  
		       max=a[i][j];	
		}
	}
	printf("the largest element in the matrix is %d",max);
	
}
