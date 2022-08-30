#include<stdio.h>
#include<stdlib.h>

void insert();
void delete();
void display();
void Front();
void isempty();
void isfull();
void Rear();

int front=-1;
int rear=-1;
int maxsize;


void insert(int queue[])
{
	int item;
	    if(((rear+1)%maxsize==front)||(front==0 && rear==maxsize-1))
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
		queue[rear]=item;
	   }
		else
		{
			rear=(rear+1)%maxsize;
			 queue[rear]=item;
		}	
     	printf("\n Value inserted\n");
        }
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
			front=(front+1)%maxsize;
		}
		printf("\n Value deleted is %d\n",item);
	    return;
	}
}

void display(int queue[])
{
	int i=front;
	if(rear==-1)
	{
		printf("\nNOTHING TO PRINT\n");
	}
	else
	{
		while(i!=rear)
		{
			printf("\n%d\n",queue[i]);
			i=(i+1)%maxsize;
		}
			printf("\n%d\n",queue[i]);
	}
}

void Front(int queue[])
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

void Rear(int queue[])
{
	if(rear==-1 || front>rear)
	{
		printf("\nEMPTY QUEUE\n");
	}
	else
	{
		printf("\n%d\n",queue[rear]);
	}
}

void isempty(int queue[])
{
	if(rear==-1 || front==-1 || (rear+1)%maxsize!=front)
	printf("\nQUEUE IS EMPTY\n");
	else
	printf("\nQUEUE IS NOT EMPTY\n");	
}

void isfull(int queue[])
{
	if(((rear+1)%maxsize==front)||(front==0 && rear==maxsize-1))
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
	printf("\n 0.exit\n 1.insert\n 2.delete\n 3.display\n 4.front\n 5.isempty\n 6.isfull\n 7.rear\n");
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
				    Front(queue);
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
			case 7:
				{
					Rear(queue);
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


