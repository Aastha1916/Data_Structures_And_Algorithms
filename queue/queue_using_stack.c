//static stack implementation

#include<stdio.h>
#include<stdlib.h>
int N;
int top1=-1,top2=-1;
int count=0;

void push1(int data,int stack1[])
{
		top1=top1+1;
		stack1[top1]=data;
}

int pop1(int stack1[])
{
		int item=stack1[top1];
		top1=top1-1;
		return item;
}

void push2(int x,int stack2[])
{
		top2=top2+1;
		stack2[top2]=x;
}

int pop2(int stack2[])
{
		int item=stack2[top2];
		top2=top2-1;
		return item;
}

void display(int stack1[])
{
	int i;
	for (i=top1;i>=0;i--)
	{
		printf("%d\n",stack1[i]);
	}
	if(top1==-1)
	printf("\n stack is empty\n");
}

void enqueue(int stack1[])
{
	if(top1==N-1)
	printf("\nOVERFLOW\n");
	else{ int data;
		printf("enter data:\n");
		scanf("%d",&data);
		push1(data,stack1);
	count++;
	printf("ELEMENT INSERTED\n");
	}
	
}

void dequeue(int stack1[],int stack2[])
{
	int i;
	if(top1==-1 && top2==-1)
	printf("QUEUE IS EMPTY\n");
	else{
		for(i=0;i<count;i++)
		{
			int element=pop1(stack1);
			push2(element,stack2);
		}
		int b=pop2(stack2);
		printf("\nTHE DEQUEUED ELEMENT IS %d\n",b);
		count--;
		for(i=0;i<count;i++)
		{
			int a=pop2(stack2);
			push1(a,stack1);
		}
	}
}
void main()
{
	printf("\nenter the size of queue:\n");
	scanf("%d",&N);
	int stack1[N],stack2[N];
	int choice;
	do
	{
		printf("\n Enter :\n 0) To exit \n 1) To enqueue\n 2)To dequeue\n 3) To display\n");
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
				   enqueue(stack1);
				    break;
				}
		    case 2:
				{
				    dequeue(stack1,stack2);
					break;
				}
			case 3:
			    {
				   display(stack1);
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
















