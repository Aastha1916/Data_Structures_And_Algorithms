#include<stdio.h>
#include<stdlib.h>
//#define maxsize 5

void insert();
void delete();
void display();
void peek();
void isempty();
void isfull();

int front=-1;
int rear=-1;
int maxsize;


void insert(int queue[])
{
	if(maxsize!=0)
	{
	int item;
	if(rear==maxsize-1)
	{
		printf("\nOVERFLOW\n");
		return;
	}
	else 
	{
		printf("\n Enter the element:\n");
	    scanf("%d",&item);
	    if(front==-1 && rear==-1)
	    {
		front=0;
		rear=0;	
	    }
    	else
	    {   
	    rear=rear+1;
	    }	
	    queue[rear]=item;
     	printf("\n Value inserted\n");
     	return;
		maxsize--;
    }
    }
    else
    printf("\nALL ELEMENTS ARE INSERTED\n");
    
}

void delete(int queue[])
{
	int item;
	if(front==-1 || front>rear)
	{
		printf("\nUNDERFLOW\n");
		return;
	}
	else
	{
		item=queue[front];
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
		{
			front=front+1;
		}
		maxsize++;
		printf("\n Value deleted is %d\n",item);
	    return;
	}
}

void display(int queue[])
{
	int i;
	if(rear==-1)
	{
		printf("\nNOTHING TO PRINT\n");
	}
	else
	{
		for(i=front;i<=rear;i++)
		{
			printf("\n%d\n",queue[i]);
		}
	}
}

void peek(int queue[])
{
	if(rear==-1)
	{
		printf("\nEMPTY QUEUE\n");
	}
	else
	{
		printf("\n%d\n",queue[front]);
	}
}

void isempty(int queue[])
{
	if(rear==-1 || front==-1 || rear<maxsize-1)
	printf("\nQUEUE IS EMPTY\n");
	else
	printf("\nQUEUE IS NOT EMPTY\n");	
}

void isfull(int queue[])
{
	if(rear==maxsize-1)
	printf("\nQUEUE IS FULL\n");
	else
	printf("\nQUEUE IS NOT FULL\n");	
}

void main()
{
	printf("\nENTER THE SIZE OF QUEUE:\n");
	scanf("%d",&maxsize);
	int queue[maxsize];
	int choice;
	do
	{
	printf("\n 0.exit\n 1.insert\n 2.delete\n 3.display\n 4.peek\n 5.isempty\n 6.isfull\n");
	printf("\nenter your choice:\n");
	scanf("%d",&choice);
	
	switch(choice)
	{
	       case 0:
		        {
		            printf("program terminated\n");
		            exit (0);
			        break;	
		        }          
		    case 1:
			    {
				    insert(queue);
				    break;
				}
	    	case 2:
				{
				   delete(queue);
					break;
				}
	     	case 3:
			    {
				    display(queue);
				    break;
				}
			case 4:
				{
				    peek(queue);
					break;
				}
			case 5:
			    {
				   isempty(queue);
				    break;
				}	
			case 6:
			    {
				    isfull(queue);
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


