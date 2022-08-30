#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*left;
	struct node*right;
};
struct node*root=0;
int deepmost()
{
	if(root==0)
	return 0;
	else
	{
		struct node*temp=root;
		while(temp->right!=0)
		temp=temp->right;
		return temp->data;
	}
}
struct node* search(struct node*node,int data)
{
	if(node==0)
	{
	printf("\nValue doesn't exist!!'");
	return 0;	
	}
	else
	{
		if(data<node->data)
		search(node->left,data);
		else if(data>node->data)
		search(node->right,data);
		else
		{
			printf("\nValue found %d",node->data);
			return node;
		}
	}
}
void deletenode(struct node*node,int value)
{
	if(node==0)
	{
		printf("\nELEMENT NOT FOUND\n");
		return;
	}
	else
	{
		struct node*temp1=search(root,value);
		struct node*temp2;
		if(temp1->left==0)
		{
		  temp2=temp1;
		  temp1=temp1->right;
		  free(temp2);	
		}
		else if(temp1->right==0)
		{
			temp2=temp1;
			temp1=temp1->left;
			free(temp2);
		}
		else
		{
			int info;
			info=deepmost();
			deletenode(root,info);
			temp1->data=info;
			
		}
	}
}
struct node*create(int data)
{
	struct node*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->left=newnode->right=0;
	newnode->data=data;
	return newnode;
}
struct node*insert()
{
	
	int data,choice;
	printf("\nEnter 0 to exit\nEnter 1 to insert: ");
	scanf("%d",&choice);
	if(choice==0)
	  return;
	else
	{
	printf("\nEnter data: ");
    scanf("%d",&data);
    struct node*newnode=create(data);
    
    printf("\nEnter left child for %d",data);
	newnode->left=insert();
	printf("\nEnter right child for %d",data);
	newnode->right=insert();
    return newnode;
    }
}
void inorder(struct node*root)
{
	if(root==0)
	return;
	else
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
void preorder(struct node*root)
{
	if(root==0)
	return;
	else
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(struct node*root)
{
	if(root==0)
	return;
	else
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}
void main()
{
	int code;
	do
	{
	printf("\nEnter 0 to exit\nEnter 1 to traverse inorder\nEnter 2 to traverse preorder\nEnter 3 to traverse postorder\nEnter 4 to search\nEnter 5 to delete\nEnter 6 to insert: ");
	scanf("%d",&code);
	switch(code)
	{
		case 0:
			printf("\nprogram terminated\n");
			exit(0);
			break;
		case 1:
			printf("\n\tINORDER TRAVERSAL\t\n");
			inorder(root);
			break;
		case 2:
			printf("\n\tPREORDER TRAVERSAL\t\n");
			preorder(root);
			break;
		case 3:
			printf("\n\tPOSTORDER TRAVERSAL\t\n");
			postorder(root);
			break;
		case 4:
			if(root==0)
			printf("\nTREE IS EMPTY\n");
			else
			{
				int info;
				printf("Enter value to search: ");
				scanf("%d",&info);
				search(root,info);
			}
			break;
		case 5:
			if(root==0)
			printf("\nTREE IS EMPTY\n");
			else
			{
				int info;
				printf("Enter value to delete: ");
				scanf("%d",&info);
				deletenode(root,info);
			}
			break;
		case 6:
			root=insert();
			break;
		default:
			printf("\nenter valid choice!!\n");
			break;
	}
}while(code!=0);
}
