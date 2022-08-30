#include<stdio.h>
#define max 10
int stack[max];
int top=-1;
void push(int n)
{
	if (top==max-1)
	{
		printf("overflow\n");
	}
	top=top+1;
	stack[top]=n;
}
void display()
{
	int i;
	for (i=top;i>=0;i--)
	{
		printf("%d ",stack[i]);
	}
	if(top==-1)
	printf("\n stack is empty\n");
}

int main()
{
	int num;
	printf("enter your number:\n");
	scanf("%d",&num);
	while(num!=0){
		push(num%2);
		num=num/2;
	}
	display();
	
}
