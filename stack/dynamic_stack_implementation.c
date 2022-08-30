//dynamic stack implementation

#include<stdio.h>
#include<stdlib.h>

void push();
void pop();
void peak();
void display();
void empty();
void full();
int length_of_stack();

struct node {
 		int data;
 		struct node*next;
	};
	
struct node*top=0,*temp;
int n,n1;


int main()
{
	int choice;
	printf("\nenter the number of elements in the stack:\n");
	scanf("%d",&n);
	n1=n;
	do
	{
		printf("\n Enter :\n 0) To exit \n 1) To push\n 2)To pop \n 3) To peak\n 4) To display\n 5) To empty\n 6) To full\n 7)To find length of stack\n");
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
			case 7:
				{
					length_of_stack();
					break;
				}
			default:
			    {
				    printf("\ninvalid argument!!\n");
				    break;
				}						
		}
	}while(choice!=0);
	return 0;
	
}

void push()
{   
   
	if(n!=0)
	{
	
    struct node*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	
	if(newnode==NULL)
	{
		printf("\nmemory not allocated\n");
	}
	else
	{
		printf("\nenter the value:\n");
		scanf("%d",&newnode->data);
		if(top==NULL)
		{
			top=newnode;
			newnode->next=0;
		}
		else
		{
			newnode->next=top;
			top=newnode;
		}
		n--;
	}
	
    }
    else{
    	printf("\nstack is full\n");
    	//n1=n;
	}
    
}

void pop()
{
	temp=top;
	if(temp==0)
	{
		printf("\n no element is present\n");
		return;
	}
	else
	{
		top=top->next;
		temp->next=NULL;
    	printf("\n%d is popped\n",temp->data);
		free(temp);
	     
	}
	n++;
}

void peak()
{
	if(top==0)
	{
		printf("\nUNDERFLOW\n");
	}
	else
	{
		int item=top->data;
		printf("\n%d\n",item);
	}
}

void display()
{
	 struct node*ptr;
	if(top==0)
	{
		printf("\nUNDERFLOW\n");
		return;
	}
	else
	{  ptr = top;
		while(ptr!=NULL)
		{
			printf("\n%d\n",ptr->data);
			ptr=ptr->next;
		}
	}
}

int length_of_stack()
{
	
	if(top==0)
	{
		printf("\nUNDERFLOW\n");
		return 0;
	}
	else
	{
		int count=1;
		struct node*temp=top;   
		while(temp->next!=0)
		{
			count++;
	        temp=temp->next;
	        
		}
		printf(" the length of the stack is %d ",count);
		return count;	
	}
	
}

void empty()
{
	int N=length_of_stack();
	if(n1==N)
	printf("\nstack is not empty\n");
	else 
	printf("\n stack is empty\n");
	
}

void full()
{
	int N=length_of_stack();
	if(n1==N)
	printf("\n stack is full\n");
	else
	printf("\n stack is not full\n");
}























