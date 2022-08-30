#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	int priority;
	struct node* next;
};
struct node*front=0;
struct node*rear=0;
struct node*newnode;
int n,n1;

void enqueue()
{
	if(n1!=0){
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==0)
	{
		printf("OVERFLOW\n");
	}
	else
	{   
		int item,prio;
		printf("ENTER THE DATA AND ITS PRIORITY:\n");
		scanf("%d %d",&item,&prio);
		newnode->data=item;
		newnode->priority=prio;
		if(front==0)
		{
			front=rear=newnode;
			newnode->next=0;
		}
     	
     	else 
     	{
     	
     		if(newnode->priority>=rear->priority)
     		{
     			rear->next=newnode;
     			rear=newnode;
     		    newnode->next=0;
		    }
		    else if(newnode->priority<front->priority)
		    {
		    	newnode->next=front;
		    	front=newnode;
			}
		    else
		    {
		    	struct node*temp=front;
		    	while(temp->next!=0 && temp->next->priority<=newnode->priority)
		    	{
		    		temp=temp->next;
				}
					newnode->next=temp->next;
					temp->next=newnode;
			}	
		}
		printf("\nNode inserted successfully!!\n");	
		n1--;
	}
	}
	else
	{
		printf("ALL NODE INSERTED\n");
	}
}

void dequeue()
{
	struct node*temp;
	if(front==0 || rear==0)
	{
		printf("UNDERFLOW\n");
		return;
	}
	else
    {
    	temp=front;
	    if(front==rear)
		front=rear=0;
	    else
		front=front->next;
	}
	printf("%d Deleted at %d priority\n",temp->data,temp->priority);
	n1++;
	free(temp);
}

void display()
{
	if(front==0)
	{
		printf("NOTHING TO PRINT\n");
	}
	else
	{
	struct node*ptr=front;
	while(ptr!=0)
	{
		printf("data:%d priority:%d\n",ptr->data,ptr->priority);
		ptr=ptr->next;
	}
	}	
}

void gethp()
{
	if(front==0 || rear==0)
	{
		printf("UNDERFLOW\n");
		return;
	}
	printf("\nThe highest priority element is %d",rear->data);
	return;
}

void main()
{
	printf("\nEnter how many nodes you want: ");
	scanf("%d",&n);
	n1=n;
	int choice;
	do
	{
	printf("\nEnter 0 to exit\n1 to enqueue\n2 to dequeue\n3 to display\n4 to get highest priority element:\n ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 0:
			printf("\nProgram Terminated\n");
			exit(0);
			break;
		case 1:
			enqueue();
			break;
		case 2:
			dequeue();
			break;
		case 3:
			display();
			break;
		case 4:
			gethp();
			break;
		default:
			printf("\nEnter Valid choice!!!\n");
			break;
	}
    }while(choice!=0);
}


