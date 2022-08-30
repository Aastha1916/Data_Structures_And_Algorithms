#include<stdio.h>
#include<stdlib.h>
#define size 5
int deque[size];
int f=-1,r=-1;
void enqueue_front(int x)
{
	if(f==-1 && r==-1)
	{
		f=0;
		r=0;
		deque[f]=x;
	}
	else if(f==0)
	{
		f=size-1;
		deque[f]=x;
	}
	else
	{
		f--;
		deque[f]=x;
	}
}
void enqueue_rear(int x)
{
    if(f==-1 && r==-1)
	{
		f=0;
		r=0;
		deque[r]=x;
	}
	else if(r==size-1 && f!=0)
	{
		r=0;
		deque[r]=x;
	}
	else
	{
		r++;
		deque[r]=x;
	}
	
}
void dequeue_front()
{
	if(f==r)
	{
		f=-1;
		r=-1;
		printf("\n THE DELETED ELEMENT IS %d\n",deque[f]);
	}
	else if(f==size-1)
	{
		f=0;
		printf("\n THE DELETED ELEMENT IS %d\n",deque[f]);
	}
	else
	{
		f++;
		printf("\n THE DELETED ELEMENT IS %d\n",deque[f]);
	}
}
void dequeue_rear()
{
    if(f==r)
	{
		f=-1;
		r=-1;
		printf("\n THE DELETED ELEMENT IS %d\n",deque[f]);
	}
	else if(r==0)
	{
		r=size-1;
		printf("\n THE DELETED ELEMENT IS %d\n",deque[r]);
	}
	else
	{
		r--;
			printf("\n THE DELETED ELEMENT IS %d\n",deque[r]);
	}
}
void display()
{
	int i=f;
	while(i!=r)
	{
		printf("%d\n",deque[i]);
		i=(i+1)%size;
	}
		printf("%d\n",deque[r]);
}
void getfront()
{
	if(f==-1 && r==-1)
	{
		printf("\nDeque is empty\n");
	}
	else
	{
		printf("\nTHE VALUE OF FRONT IS %d",deque[f]);
	}
}
void getrear()
{
	if(f==-1 && r==-1)
	{
		printf("\nDeque is empty\n");
	}
	else
	{
		printf("\nTHE VALUE OF REAR IS %d",deque[r]);
	}
}
void isempty()
{
	if(r==-1 || f==-1 || (r+1)%size!=f)
	printf("\nQUEUE IS EMPTY\n");
	else
	printf("\nQUEUE IS NOT EMPTY\n");	
}
void isfull()
{
	if(((r+1)%size==f)||(f==0 && r==size-1))
	printf("\nQUEUE IS FULL\n");
	else
	printf("\nQUEUE IS NOT FULL\n");	
}

int main()
{
//	printf("\nENTER THE SIZE OF QUEUE:\n"); 
//	scanf("%d",&msize);
//	int queue[size];
	int choice,x,ch;
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
			    	if(((r+1)%size==f)||(f==0 && r==size-1))
	                {
             		printf("\nOVERFLOW\n");
            		break;
                	}
			    	printf("ENTER THE DATA:\n");
			    	scanf("%d",&x);
			        printf("ENTER YOUR CHOICE:\n1.insert from front\n2.insert from rear\n");
			        scanf("%d",&ch);
			        switch(ch)
			        {
			        	case 1:enqueue_front(x);break;
			        	case 2:enqueue_rear(x); break;
                        default:{
				                printf("\ninvalid argument!!\n");
				                 break;} 
					}
					break;
			   	}
	    	case 2:
				{
					if(f==-1 || f>r)
                	{
            		printf("\nUNDERFLOW\n");
            		break;
                	}
			        printf("ENTER YOUR CHOICE:\n1.delete from front\n2.delete from rear\n");
			        scanf("%d",&ch);
			        switch(ch)
			        {
			        	case 1:dequeue_front(x);break;
			        	case 2:dequeue_rear(x); break;
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
					getrear();
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
