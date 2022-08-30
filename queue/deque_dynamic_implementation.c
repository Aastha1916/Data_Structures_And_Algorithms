#include<stdio.h>
#include<stdlib.h>
int size,n1,i;
struct node{
	int data;
	struct node*next;
	struct node*prev;
	};
struct node*front=NULL;
struct node*rear=NULL;
struct node*newnode;
void front_insert(struct node*newnode)
{
	if(n1!=0)
	{
	int item;
	printf("enter the data :\n");
	scanf("%d",&item);
	newnode->data=item;
		if(front==NULL)
		{
			newnode->next=NULL;
			newnode->prev=NULL;
			front=newnode;
			rear=newnode;
	   }
	   else
	   {
	   	    newnode->prev=NULL;
	   	    newnode->next=front;
	   	    front->prev=newnode;
			front=newnode;
	   }
	   n1--;
	printf("node inserted\n");
	}
	else
    printf("\nALL ELEMENTS ARE INSERTED\n");
}
void rear_insert(struct node*newnode)
{
	if(n1!=0)
	{
	struct node*temp;
	int item;
	printf("\nenter the data :\n");
	scanf("%d",&item);
	newnode->data=item;
		if(front==NULL)
		{
		    newnode->next=NULL;
			newnode->prev=NULL;
			front=newnode;
			rear=newnode;
	   }
	   else
	   {
	   	    newnode->prev=rear;
	   	    rear->next=newnode;
	   	    newnode->next=0;
	   	    rear=newnode;
	   }
	   n1--;
	printf("\nnode inserted\n");
	}
	else
    printf("\nALL ELEMENTS ARE INSERTED\n");
}
void front_delete()
{
	struct node*temp;
    if(front->next==NULL)
	{
		temp=front;
		front=rear=NULL;
		free(temp);
		printf("\nonly node of the list is deleted\n");
	}
	else
	{
		temp=front;
		front=front->next;
		front->prev=0;
		free(temp);
        printf("\nNode deleted\n");
	}
	n1++;
}
void rear_delete()
{
	struct node*ptr;
	if (front->next==0)
	{
		ptr=front;
		front=rear=NULL;
		free(ptr);
		printf("\nonly node of the list is deleted\n");
	}
	else
	{
		ptr=rear;
		rear=rear->prev;
		rear->prev->next=0;
		free(ptr);
		printf("\ndeleted node from last\n");
	}
		n1++;
}
void display()
{
	struct node*ptr;
	ptr=front;
	if(front==NULL)
	{
		printf("\nNothing to print\n");
	}
	else
	{
		while(ptr->next!=NULL)
		{
			printf("\n%d",ptr->data);
			ptr=ptr->next;
		}
		printf("\n%d",ptr->data);
	}
}
int count_node()
{
	if(front==NULL)
	printf("\nEmpty list\n");
	else{
	int i=1;
	struct node*ptr;
	ptr=front;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
		i++;
	}
	printf("%d nodes",i);
	return i;
	}
	
}
void getfront()
{
	if(front==0 && rear==0)
	{
		printf("\nDeque is empty\n");
	}
	else
	{
		printf("\nTHE VALUE OF FRONT IS %d",front->data);
	}
}
void getrear()
{
	if(front==0 && rear==0)
	{
		printf("\nDeque is empty\n");
	}
	else
	{
		printf("\nTHE VALUE OF REAR IS %d",rear->data);
	}
}
void isempty()
{
	int N=count_node();
	if(size==N)
	printf("\nstack is not empty\n");
	else 
	printf("\n stack is empty\n");
}
void isfull()
{
	int N =count_node();
	if(size==N)
	printf("\n stack is full\n");
	else
	printf("\n stack is not full\n");
}

int main()
{
	printf("\nENTER THE SIZE OF QUEUE:\n"); 
	scanf("%d",&size);
	n1=size;
	int choice,ch;
	do
	{
	printf("\n 0.exit\n 1.insert\n 2.delete\n 3.display\n 4.front\n 5.isempty\n 6.isfull\n 7.rear\n8.count node\n");
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
			    	int ch;
			    	newnode=(struct node*)malloc(sizeof (struct node));
			    	if(newnode==NULL)
                	{
            		printf("\nOVERFLOW\n");
            		break;
                	}
			        printf("ENTER YOUR CHOICE:\n1.insert from front\n2.insert from rear\n");
			        scanf("%d",&ch);
			        switch(ch)
			        {
			        	case 1:front_insert(newnode);break;
			        	case 2:rear_insert(newnode); break;
                        default:{
				                printf("\ninvalid argument!!\n");
				                 break;} 
					}
					break;
			   	}
	    	case 2:
				{
					int ch;
					if(front==NULL)
					{
					printf("\nUNDERFLOW\n");
					}
			        printf("ENTER YOUR CHOICE:\n1.delete from front\n2.delete from rear\n");
			        scanf("%d",&ch);
			        switch(ch)
			        {
			        	case 1:front_delete();break;
			        	case 2:rear_delete(); break;
                        default:{
				                printf("\ninvalid argument!!\n");
				                 break;} 
					}
			         
					break;
				}
	     	case 3:
			    {
				    display();
				    break;
				}
			case 4:
				{
				    getfront();
					break;
				}
			case 5:
			    {
				   isempty(size);
				    break;
				}	
			case 6:
			    {
				    isfull(size);
				    break;
				}
			case 7:
				{
					getrear();
					break;
				}
			case 8:
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
