#include<stdio.h>
#include<stdlib.h>

void insert();
void delete();
void display();
void peek();
void isempty();
void isfull();
int count_node();

struct node
{
	int data;
	struct node*next;
};
struct node*front=0;
struct node*rear=0;
int n,n1;

void insert()
{
	if(n1!=0)
	{
	struct node*newnode;
	int item;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("\nOVERFLOW\n");
		return;
	}
	else
	{
		printf("enter the data :\n");
		scanf("%d",&item);
		newnode->data=item;
		newnode->next=0;
		if(front==NULL)
		{
			front=newnode;
			rear=newnode;
			newnode->next=front;
	   }
	   else
	   {
	   	    rear->next=newnode;
	   	    rear=newnode;
	   	    newnode->next=front;
	   	   
	   }
	   printf("node inserted");
	   n1--;
	}
	}
    else
    printf("\nALL ELEMENTS ARE INSERTED\n");
}
void delete()
{
	struct node*temp;
	if(front==NULL)
	{
		printf("\nUNDERFLOW\n");
		return;
	}
	else
	{
		temp=front;
		if(front==rear)
		{
			front=0;
			rear=0;
		}
		else
		{
		   front=front->next;
		   rear->next=front;	
		}
		free(temp);
		printf("\nNode deleted\n");
	    n1++;
	}	
}
void display()
{
	struct node*ptr;
	ptr=front;
	if(front==NULL)
	{
		printf("\nNothing to print\n");
		return;
	}
	else
	{
		while(ptr->next!=front)
		{
			printf("%d\n",ptr->data);
			ptr=ptr->next;
		} 
		printf("%d\n",ptr->data);            
	}
}

void peek()
{
	if(rear==0 || front==0)
	{
		printf("\nEMPTY QUEUE\n");
	}
	else
	{
		printf("\n%d\n",front->data);
	}
}

int count_node()
{
	if(front==NULL)
	{
		printf("\nEmpty list\n");
	    return 0;	
	}
	else
	{
	int i=1;
	struct node*ptr;
	ptr=front;
	while(ptr->next!=front)
	{ i++;
		ptr=ptr->next;
		
	}
	printf("%d nodes",i);
	return i;
	}
	
}

void isempty()
{
	int N=count_node();
	if(n==N)
	printf("\nstack is not empty\n");
	else 
	printf("\n stack is empty\n");
	
}

void isfull()
{
	int N =count_node();
	if(n==N)
	printf("\n stack is full\n");
	else
	printf("\n stack is not full\n");
}

void main()
{
	printf("\nENTER THE SIZE OF QUEUE:\n");
	scanf("%d",&n);
	n1=n;

	int choice;
	do
	{
	printf("\n 0.exit\n 1.insert\n 2.delete\n 3.display\n 4.peek\n 5.isempty\n 6.isfull\n 7.count node\n");
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
				    insert();
				    break;
				}
	    	case 2:
				{
				   delete();
					break;
				}
	     	case 3:
			    {
				    display();
				    break;
				}
			case 4:
				{
				    peek();
					break;
				}
			case 5:
			    {
				   isempty();
				    break;
				}	
			case 6:
			    {
				    isfull();
				    break;
				}
			case 7:
				{
					count_node();
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



