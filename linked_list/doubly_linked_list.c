//doubly linked list

#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
	struct node*prev;
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
void specified_ele_ins()
{
		if(head==0)
	{
			printf("\nlist is empty\n");
			return;
	}
	int ch,flag=0;
	do{
	
		printf("0.exit\n 1.before element\n 2.after element\n enter your choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0:  return;break;
			case 1: flag=0;break;
			case 2:  flag=1;break;
			default: {
			printf("invalid argument\n");
				return;
				break;
			}
		}
    struct node*newnode,*ptr;
    int item,element;
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
		printf("\nenter the element:\n");
	    scanf("%d",&element);
	    ptr=head;
	    while(ptr->data!=element)
	    {
	    	ptr=ptr->next;
	        if(ptr==0)
	       printf("\n element not found\n");
		}
		if(ptr->data==element)
		{
			if(flag==1)
			{
				if(ptr->next==0)
				newnode->next=0;
				else{
			    newnode->next=ptr->next;
			    newnode->next->prev=newnode;}
			newnode->prev=ptr;
			ptr->next=newnode;
			
		   }
		   if(flag==0)
		{    
		       if(ptr->prev==0){
		       newnode->prev=0;
		       head=newnode;}
		       else{
		       newnode->prev=ptr->prev;
		       ptr->prev->next=newnode;
		         }
			newnode->next=ptr;
			ptr->prev=newnode;
		}
		printf("node inserted");
     	}
     	else
	printf("\nelement not found\n");
    }
	}while(ch!=0);
}
void begin_insert()
{
	struct node*newnode;
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
			newnode->next=NULL;
			newnode->prev=NULL;
			head=newnode;
			
	   }
	   else
	   {
	   	    newnode->prev=NULL;
	   	    newnode->next=head;
	   	    head->prev=newnode;
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
		    newnode->next=NULL;
			newnode->prev=NULL;
			head=newnode;
			
	   }
	   else
	   {
	   	    temp=head;
	   	    while(temp->next!=0)
	   	    {
	   	    	temp=temp->next;
			   }
			   temp->next=newnode;
	   	    newnode->prev=temp;
	   	    newnode->next=0;
	   }
	}
	printf("\nnode inserted\n");
}

void random_insert()
{
	int ch,flag=0;
	do{
	
		printf("0.exit\n 1.before location\n 2.after location\n 3.at location\n enter your choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0:  return;break;
			case 1: flag=-2;break;
			case 2:  flag=0;break;
			case 3:   flag=-1;break;
			default: {
			printf("invalid argument\n");
				return;
			}
		}
	
	int i,loc,item;
	struct node*newnode,*temp;
	newnode=(struct node*)malloc(sizeof (struct node));
	if(newnode==NULL)
	{
		printf("\nOVERFLOW\n");
	}
	else
	{
		if(head==NULL)
		{
			printf("list is empty");
	   }
	   else
	   {
	   	    printf("\nenter the location:\n");
		    scanf("%d",&loc);
		    if(loc==1 && (flag==-2||flag==-1))
		    {
		    	begin_insert();
		    	return;
			}
			else
			{
				printf("\nenter the data :\n");
		scanf("%d",&item);
		newnode->data=item;
	   	    temp=head;
	   	    for(i=1;i<loc+flag;i++)
	   	    {
	   	    	temp=temp->next;
			   }
	   	    
			   newnode->next=temp->next;
			   newnode->prev=temp;
			   temp->next=newnode;
			   temp->next->prev=newnode;
			   
			   printf("\nnode inserted\n");
	      }
	       
     }
	}
	}while(ch!=0);
}

void begin_delete()
{
	struct node*temp;
	if(head==NULL)
	{
		printf("\nlist is empty\n");
	}
	else if(head->next==NULL)
	{
		head=NULL;
		free(head);
		printf("\nonly node of the list is deleted\n");
	}
	else
	{
		temp=head;
		head=head->next;
		head->prev=0;
		free(temp);
        printf("\nNode deleted\n");
	}
}

void last_delete()
{
	struct node*ptr;
	if(head==NULL)
	{
		printf("\nlist is empty\n");
	}
	else if (head->next==0)
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
			ptr=ptr->next;
		}
		ptr->prev->next=NULL;
		free(ptr);
		printf("\ndeleted node from last\n");
	}
}

void specified_ele_del()
{
	if(head==0)
	{
			printf("\nlist is empty\n");
			return;
	}
	int ch,flag=0;
	do{
	
		printf("0.exit\n 1.before element\n 2.after element\n 3.at given element\n enter your choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0:  return;break;
			case 1: flag=-1;break;
			case 2:  flag=1;break;
			case 3:   flag=0;break;
			default: {
			printf("invalid argument\n");
				return;
				break;
			}
		}
	struct node*ptr,*temp;
	int element;
	printf("\nenter the element:\n");
	scanf("%d",&element);
	temp=head;
	while(temp->data!=element)
	{
	temp=temp->next;
	if(temp->next==0)
	printf("\n element not found\n");
	}
	
	if(temp->data==element)
	{
		if(flag==1)
		{
			if(temp->next==0)
			{
				printf("\n list end\n can't delete\n");
				return;
			}
		        ptr=temp->next;
		        temp->next=ptr->next;
		        ptr->next->prev=temp;
		}
		if(flag==-1)
		{
			if(temp->prev==0)
			{
				printf("\n list starting\n can't delete\n");
				return;
			}
			else if(temp->prev->prev==0)
			{
		        begin_delete();
		        return;
	        }
	        else
			{
	        	ptr=temp->prev;
		        temp->prev=ptr->prev;
		        ptr->prev->next=temp;
			}
	    }
		if(flag==0)
		{
			if(temp->prev==0)
			{
				begin_delete();
		        return;
			}
			if(temp->next==0)
			{
				last_delete();
				return;
			}
			else
			{
				ptr=temp;
			    temp->prev->next=ptr->next;
			    temp->next->prev=ptr->prev;
			}
		}
		free(ptr);
		printf("\n node deleted\n");
	}
	else
	printf("\nelement not found\n");
    }while(ch!=0);
}

void random_delete()
{
	if(head==0)
	{
			printf("\nlist is empty\n");
			return;
	}
	int ch,flag=0;
	do{
	
		printf("0.exit\n 1.before location\n 2.after location\n 3.at location\n enter your choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0:  return;break;
			case 1: flag=-2;break;
			case 2:  flag=0;break;
			case 3:   flag=-1;break;
			default: {
			printf("invalid argument\n");
				return;
				break;
			}
		}
	struct node*ptr,*temp;
	int loc,i;
	printf("\nenter the location of the node:\n ");
	scanf("%d",&loc);
	if((loc==2 && flag==-2)||(loc==1 && flag==-1))
	{
		begin_delete();
		return;
	}
	if(loc==1 && flag==-2)
	{
		printf("\nno element is present\n");
		return;
	}
	else
	{
		ptr=head;
	for(i=0;i<loc+flag;i++)
	{
		ptr=ptr->next;
		if(ptr->next==NULL)
		{
			printf("\ncan't delete\n");
		}
	}
	if(ptr->next->next==0)
	{
		ptr->next=0;
	}
	else
	{
	    temp=ptr->next;
        ptr->next=temp->next;
        temp->next->prev=ptr;
    	free(ptr);	
	}
	printf("\ndeleted node %d location\n",loc);
	}
      }while(ch!=0);
}

void search()
{
	struct node*ptr;
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
		while(ptr->data!=item && ptr->next!=NULL)
		{
			ptr=ptr->next;
			i++;
		}
		if(ptr->data==item)
		{
		    printf("\n %d found at %d location\n",item,i);
		}
		else
		printf("\nelement not found\n");
	}
}

void display()
{
	struct node*ptr;
	ptr=head;
	if(ptr==NULL)
	{
		printf("\n nothing to print\n");
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

void count_node()
{
	if(head==NULL)
	printf("\nEmpty list\n");
	else{
	int i=1;
	struct node*ptr;
	ptr=head;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
		i++;
	}
	printf("%d nodes",i);}
}

void main()
{
	int choice;
	do
	{
	printf("\n 0.to exit\n 1.insertion at begginning\n 2.insertion at a given position\n 3.insertion at end\n 4.deletion at begginning\n 5.deletion at a given position\n 6.deleltion at end\n 7.search\n 8.display\n 9.count node\n 10.specific element deletion\n 11.specific element insertion\n");
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
					display();
					break;
				}	
			case 9:
				{
					count_node();
					break;
				}
			case 10:
			    {
				    specified_ele_del();
					break;
			    }	
			case 11:
			    {
				specified_ele_ins();  
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












