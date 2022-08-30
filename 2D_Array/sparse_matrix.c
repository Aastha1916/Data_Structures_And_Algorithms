//sparse matrix
#include<stdio.h>
int main()
{
	int r,c,i,j;
	printf("enter number of rows and columns: \n");
	scanf("%d  %d",&r  ,&c);
	int a[r][c];
	printf("enter elements of matrix A: \n");
	for(i=0;i<=r-1;i++)
	{
		for(j=0;j<=c-1;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	int size=0;
	for(i=0;i<=r-1;i++)
	{
		for(j=0;j<=c-1;j++)
		{
			if (a[i][j]!=0)
			size++;
		}
	}
	
	int b[3][size];
	int k=0;
	
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if (a[i][j]!=0)
			{
				b[0][k]=i;
				b[1][k]=j;
				b[2][k]=a[i][j];
				k++;
			}
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<size;j++)
		{
			printf(" %d ",b[i][j]);
			printf("\t");
		}
		printf("\n");
	}
	return 0;
	
}

