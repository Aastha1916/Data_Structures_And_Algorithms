//implementation of priority queue using array(two separate arrays for data and priority) 

#include<stdio.h>
#include<stdlib.h>
#define N 10
int q[N],p[N];
int r=-1;
int f=-1;

int choice,n,data,priority,n1,item,prio,i,temp1;

void update(int queue[],int f,int r,int q[] )
{
	int temp;
	for(i=r;i>f;i--)
	{
		if (queue[i] < queue[i-1]){			
			temp = queue[i];
			queue[i] = queue[i-1];
			queue[i-1] = temp;
			
			temp = q[i];
			q[i] = q[i-1];
			q[i-1] = temp;
		}
	}
	
}
void enqueue()
{
	if(n1!=0)
	{
	if(f==0 && r==N-1)
	{
		printf("OVERFLOW\n");
	}
	else 
	{
		printf("Enter data and its priority:\n");
		scanf("%d %d",&data,&priority);
		if(f==-1 && r==-1)
		f=r=0;
	    else
		r++;
		q[r]=data;
		p[r]=priority;
		update(p,f,r,q);
		printf("\n Value inserted\n");
		n1--;
	}
    }
    else
    {
    	 printf("\nALL ELEMENTS ARE INSERTED\n");
	}	
}
void dequeue()
{
	
	if(f==-1 || f>r)
	{
		printf("UNDERFLOW\n");
	}
	else
	{
		item=q[f];
		prio=p[f];
		if(f==r)
		f=r=-1;
		else
		f++;
		printf("%d deleted at %d priority\n",item,prio);
		n1++;
	}
}

void print()
{
	if(f==-1)
	printf("NOTHING TO PRINT!!\nEMPTY QUEUE");
	else
	{   
		for(i=f;i<=r;i++)
		{
			printf("data: %d   priority: %d\n",q[i],p[i]);
		}
	}
}
int main()
{
	printf("Enter number of elements:\n");
				scanf("%d",&n);
				n1=n;
				if(n>N)
				{
					printf("Input size is not valid!!\n");
					return;
				}
	do{
		printf("0.Exit\n1.Enqueue\n2.Display\n3.Dequeue\nENTER YOUR CHOICE:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:
				{
				printf("PROGRAM TERMINATED!!\n");
				exit(0);
				break;
			}
			case 1:
				{
				enqueue();
				break;
				}
			case 2:
				{
				print();
				break;
				}
			case 3:
				{
				dequeue();
				break;
				}
			default:
				{
			 	printf("INVALID ARGUMENT!!\n");	
			 	break;
			 	}
		}
	}while(choice!=0);
	return 0;
}
