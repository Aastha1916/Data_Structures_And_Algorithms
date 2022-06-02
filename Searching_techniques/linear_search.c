//linear search technique is applicable for searching any element in unsorted arrays
//In case of same elements present in the array , first occuring position of element will be returned
#include<stdio.h>
int search_unsorted(int a[],int key,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==key)//comparing each element of the array with the given key element which we want to search
		return i+1;//if the condition holds true , we return the position of the element in the array
		
	}
	return -1;//represents key element is not present in the array
}
int main()
{
	int key,pos,i,n;
	//int a[]={ 2,55,1,34,99,4};
	//int n= sizeof (a)/sizeof (a[0]);
	printf("Enter the size of your Array:\n ");
	scanf("%d",&n);
	int a[n];
	printf("Enter elements of your Array:\n ");
	for (i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Given array is:");
	for(i=0;i<n;i++)
	{
		printf(" %d ",a[i]);
	}
	printf("\nEnter the key element :\n");
	scanf("%d",&key);
	pos=search_unsorted(a,key,n);//calling function to search element
	if (pos>0)
	printf("Element found at %d postition\n",pos);
	else
	printf("Element not found !!");
	return 0;
}
