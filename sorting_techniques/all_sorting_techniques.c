#include<stdio.h>
#include<stdlib.h>
int n,i,lb,ub,l,h;
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void print_array(int a[],int n)
    {
    	for(i=0;i<n;i++)
	{
		printf(" %d ",a[i]);
	} 
	}	
int partition(int a[],int l,int h)
{
	int pivot= a[l];
	int start= l;
	int end = h;
	while(start<end)
	{
		while(a[start]<=pivot)
		start++;
		while(a[end]>pivot)
		end--;
		if(start<end)
		swap(&a[start],&a[end]);
	}
	swap(&a[end],&a[l]);
	return end;
}
void merge(int a[],int lb,int mid,int ub)
{
    int b[ub+1];
	int i=lb;
	int j=mid+1;
	int k=lb;
	while(i<=mid && j<=ub)
	{
		if(a[i]<a[j])
		{
			b[k]=a[i];
			i++;
			k++;
		}
		else
		{
			b[k]=a[j];
			j++;
			k++;
		}
    }
if(i>mid)
{  while(j<=ub)
	{
		b[k]=a[j];
		j++;
		k++;
	}
}
	else
{
    while(i<=mid)
	{
		b[k]=a[i];
		i++;
		k++;
	}
}

for(i=lb;i<=ub;i++)
    a[i]=b[i];
}
void insertion_sort(int a[],int n)
{
	int i,j,key;
	for(i=1;i<n;i++)
	{
		key=a[i];
		j=i-1;
		while(j>=0 && a[j]>key)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
}
void selection_sort(int a[],int n)
{
	int min_idx,i,j;
	for(i=0;i<n-1;i++)
	{
	   int min_idx=i;
	   for(j=i+1;j<n;j++)
	   {
	   if(a[min_idx]>a[j])
	   {
	     min_idx=j;
	     swap(&a[min_idx],&a[i]);
	   }
       }
    }
}
void Bubble(int a[],int n)
{
	int j,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
			temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
		    }
		}
	}
}
void quick_sort(int a[],int l,int h)
{	
	if(l<h)
	{
		int pivot = partition(a,l,h);
		quick_sort(a,l,pivot-1);
		quick_sort(a,pivot+1,h);
	}
	
}
void merge_sort(int a[],int lb,int ub)
{
	if(lb<ub)
	{
	  int mid=(lb+ub)/2;
	  merge_sort(a,lb,mid);
	  merge_sort(a,mid+1,ub);
	  merge(a,lb,mid,ub);
	}
	
}
void main()
{
	printf("enter number of elements:");
	scanf("%d",&n);
	int a[n];
	printf("enter elements in the array:");
	for (i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int choice;
	do
	{
		printf("\n Enter :\n 0) To exit \n 1)Insertion sort\n 2)Selection sort \n 3) Bubble sort\n 4) Merge sort\n 5) Quick sort\n");
		printf("\nenter your choice:\n");
		scanf("%d",&choice) ;	
		switch(choice)
		{
			case 0:
				{
					printf("\nprogram terminated\n");
					exit (0);
					break;
				}
			case 1:
			    {
				    printf("array after sorting :\n");
	                insertion_sort(a,n);
	                print_array(a,n); 
				    break;
				}
		    case 2:
				{
				    printf("array after sorting :\n");
	                selection_sort(a,n);
	                print_array(a,n); 
					break;
				}
			case 3:
			    {
				   	printf("array after sorting :\n");
                    Bubble(a,n);
                    print_array(a,n); 
				    break;
				}
			case 4:
				{   
			    	int lb=0;
                	int ub=n-1;
				    merge_sort(a,lb,ub);
                	printf("array after sorting :\n");
                  	print_array(a,n);
					break;
				}
			case 5:
			    {
			    	int l=0;
	                int h=n-1;
	                printf("array after sorting :\n");
				   	quick_sort(a,l,h);
	                print_array(a,n);
                	
				    break;
				}	
			default:
			    {
				    printf("\ninvalid argument!!\n");
				    break;
				}						
		}
	}while(choice!=0);
}
