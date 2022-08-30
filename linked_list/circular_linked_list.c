//circular singly linked list

#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
};
struct node*head=NULL;
/*
void begin_insert();
void last_insert();
void random_insert();
void begin_delete();
void last_delete();
void random_delete();
void search();
void display();
void count_node();
*/
void begin_insert()
{
	struct node*newnode,*temp;
	int item;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("\nOVERFLOW\n");
	}
	else
	{
		printf("enter the data :\n");
		scanf("%d",&item);
		newnode->data=item;
		if(head==NULL)
		{
			head=newnode;
			newnode->next=head;
			
	   }
	   else
	   {
	   	    temp=head;
	   	    while(temp->next!=head)
	   	    {
	   	    	temp=temp->next;
			   }
			   
	   	    newnode->next=head;
	   	    temp->next=newnode;
			head=newnode;
	   }
	}
	printf("node inserted");
}

void last_insert()
{
	struct node*newnode,*temp;
	int item;
	newnode=(struct node*)malloc(sizeof (struct node));
	if(newnode==NULL)
	{
		printf("\nOVERFLOW\n");
	}
	else
	{
		printf("\nenter the data :\n");
		scanf("%d",&item);
		newnode->data=item;
		if(head==NULL)
		{
			head=newnode;
			newnode->next=head;
			
	   }
	   else
	   {
	   	    temp=head;
	   	    while(temp->next!=head)
	   	    {
	   	    	temp=temp->next;
			   }
			   temp->next=newnode;
	   	    newnode->next=head;
	   }
	}
	printf("\nnode inserted\n");
}

void random_insert()
{
	int i,loc,item;
	struct node*newnode,*temp;
	newnode=(struct node*)malloc(sizeof (struct node));
	if(newnode==NULL)
	{
		printf("\nOVERFLOW\n");
	}
	else
	{
		printf("\nenter the data :\n");
		scanf("%d",&item);
		newnode->data=item;
		if(head==NULL)
		{
			head=newnode;
			newnode->next=head;
	   }
	   else
	   {
	   	    printf("\nenter the location:\n");
		    scanf("%d",&loc);
	   	    temp=head;
	   	    for(i=0;i<loc-1;i++)
	   	    {
	   	    	temp=temp->next;
	   	    }
			   newnode->next=temp->next;
			   temp->next=newnode;
	   }
	}
	printf("\nnode inserted\n");
}

void begin_delete()
{
	struct node*temp;
	if(head==NULL)
	{
		printf("\nlist is empty\n");
	}
	else if(head->next==head)
	{
		head=NULL;
		free(head);
		printf("\nonly node of the list is deleted\n");
	}
	else
	{
		temp=head;
		while(temp->next!=head){
			temp=temp->next;
		}
		temp->next=head->next;
		free(head);
		head=temp->next;
		printf("\nNode deleted\n");
	}
}

void last_delete()
{
	struct node*temp,*ptr;
	if(head==NULL)
	{
		printf("\nlist is empty\n");
	}
	else if (head->next==head)
	{
		head=NULL;
		free(head);
		printf("\nonly node of the list is deleted\n");
	}
	else
	{
		ptr=head;
		while(ptr->next!=NULL)
		{
			temp=ptr;
			ptr=ptr->next;
		}
		temp->next=ptr->next;
		free(ptr);
		printf("\ndeleted node from last\n");
	}
}

void random_delete()
{
	struct node*temp,*ptr;
	int loc,i;
	if(head==NULL)
	printf("\nno element is present\n");
	else
	{
	printf("\nenter the location of the node after which you want to delete the node\n ");
	scanf("%d",&loc);
	ptr=head;
	for(i=0;i<loc-1;i++)
	{
		temp=ptr;
		ptr=ptr->next;
		if(ptr==head)
		{
			printf("\ncan't delete\n");
		}
	}
	temp->next=ptr->next;
	free(ptr);
	printf("\ndeleted node %d location",loc);}
}

void search()
{
	struct node*ptr,*temp;
	int item,i=1;
	ptr=head;
	if(ptr==NULL)
	{
		printf("\nEmpty list\n");
	}
	else
	{
		printf("\nenter item which you want to search:\n");
		scanf("%d",&item);
		while(ptr->data!=item && ptr->next!=head)
		{
			ptr=ptr->next;
			i++;
		}
		if(ptr->data==item)
		{
			temp=ptr;
		    printf("\n %d found at %d location\n",item,i);
		}
		else
		printf("\nelement not found\n");
	}
}

void display_start()
{
	struct node*ptr;
	ptr=head;
	if(ptr==NULL)
	{
		printf("\n nothing to print\n");
	}
	else
	{
		while(ptr->next!=head)
		{
			printf("\n%d",ptr->data);
			ptr=ptr->next;
		}
		printf("\n%d",ptr->data);
	}
}

void count_node()
{
	if(head==NULL)
	printf("\nEmpty list\n");
	else{
	int i=1;
	struct node*ptr;
	ptr=head;
	while(ptr->next!=head)
	{
		ptr=ptr->next;
		i++;
	}
	printf("%d nodes",i);
	}
}

void main()
{
	int choice;
	do
	{
	printf("\n 0.to exit\n 1.insertion at begginning\n 2.insertion at a given position\n 3.insertion at end\n 4.deletion at begginning\n 5.deletion at a given position\n 6.deleltion at end\n 7.search\n 8.display or traverse(from start)\n 9.count node\n");
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
				    begin_insert();
				    break;
				}
		case 2:
				{
				    random_insert();
					break;
				}
		case 3:
			    {
				    last_insert();
				    break;
				}
			case 4:
				{
				    begin_delete();
					break;
				}
			case 5:
			    {
				   random_delete();
				    break;
				}	
			case 6:
			    {
				    last_delete();
				    break;
				}
			case 7:
				{
					search();
					break;
				}
			case 8:
				{
					display_start();
					break;
				}	
			case 9:
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












