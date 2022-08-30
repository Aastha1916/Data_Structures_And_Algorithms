#include<stdio.h>
int main()
{
	int r1,r2,c1,c2,i,j,k;
	printf("enter number of rows r1 of first matrix A:\n ");
	scanf("%d",&r1);
	printf("enter number of columns c1 of first matrix A:\n ");
	scanf("%d",&c1);
	printf("enter number of rows r2 of second matrix: B\n ");
	scanf("%d",&r2);
	printf("enter number of columns c2 of second matrix B:\n ");
	scanf("%d",&c2);
	int a[r1][c1], b[r2][c2], c[r1][c2];
	printf("enter elements of first matrix A:\n");
	for (i=0;i<=r1-1;i++)
	{
		for(j=0;j<=c1-1;j++)
		{
			scanf("%d",&a[i][j]);
			
		}
	}
	printf("enter elements of second matrix B:\n");
	for(i=0;i<=r2-1;i++)
	{
		for(j=0;j<=c2-1;j++)
		{
			scanf("%d",&b[i][j]);
			
		}
	}
	if(c1 != r2)
	printf("multiplication not possible\n");
	else
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c2;j++)
		{
			int temp=0;
			for(k=0;k<c1;k++)
			{
				temp=temp+ a[i][k]*b[k][j];
			}
			c[i][j]=temp;
		}
	}
	printf("matrix multiplication:\n");
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c2;j++)
		{
		printf(" %d ",c[i][j]);
	    }
	    printf("\n");
	}
	return 0;
}
