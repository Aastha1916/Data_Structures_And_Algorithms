//static stack implementation

#include<stdio.h>
#include<stdlib.h>
int N=5;
int stack[5];

int top=-1;
void push();
void pop();
void peak();
void display();
void empty();
void full();

void main()
{
	/*int N;
	printf("\nenter the size of stack:\n");
	scanf("%d",&N);*/
	int n,choice;
	printf("\nenter the number of elements in the stack:\n");
	scanf("%d",&n);
	do
	{
		printf("\n Enter :\n 0) To exit \n 1) To push\n 2)To pop \n 3) To peak\n 4) To display\n 5) To empty\n 6) To full\n");
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
				    push();
				    break;
				}
		    case 2:
				{
				    pop();
					break;
				}
			case 3:
			    {
				    peak();
				    break;
				}
			case 4:
				{
				    display();
					break;
				}
			case 5:
			    {
				    empty();
				    break;
				}	
			case 6:
			    {
				    full();
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

void push()
{
	int val;
	if(top==N-1)
	printf("\nOVERFLOW\n");
	else
	{
		printf("\n enter the value: \n");
		scanf("%d",&val);
		top=top+1;
		stack[top]=val;
	}
}

void pop()
{
	if(top==-1)
	printf("\nunderflow\n");
	else
	{
		int item=stack[top];
		top=top-1;
		printf("\n%d is popped\n",item);
	}
}

void peak()
{
	if(top==-1)
	printf("\nunderflow\n");
	else
	{
		int item=stack[top];
		printf("%d",item);
	}
}

void display()
{
	int i;
	for (i=top;i>=0;i--)
	{
		printf("%d\n",stack[i]);
	}
	if(top==-1)
	printf("\n stack is empty\n");
}

void empty()
{
	if(top==-1)
	printf("\nstack is empty\n");
	else
	printf("\n stack is not empty\n");
}

void full()
{
	if(top==N-1)
	printf("\n stack is full\n");
	else
	printf("\n stack is not full\n");
}

















