#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node*left,*right;
};
struct node*root=0;
int item;
struct node*newnode(int item)
{
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	temp->data=item;
	temp->left=temp->right=0;
	return temp;
}

void inorder(struct node*root)
{
	if(root==0)
	return;
	else
	{
		inorder(root->left); //traverse left subtree
		printf("%d ->",root->data);
		inorder(root->right);
	}
}

struct node*insert(struct node*root,int item)
{
	if(root==0)
	{
		printf("node inserted\n");
		return newnode(item);
	} 
	if(item<root->data)
		root->left=insert(root->left,item);
	else
		root->right=insert(root->right,item);	
	return root;
}

//finding tha minimum number in the right subtree to replace it with the deleting node
struct node*minValueNode(struct node*node)
{
	struct node*current=node;
	//finding the leftmost tree
	while(current && current->left!=0)
	current=current->left;
	//minimum node is found
	return current;
}

struct node*deletenode(struct node*root,int item)
{
	if(root==0)return;
	
	if(item<root->data)
	root->left=deletenode(root->left,item);
	else if(item>root->data)
	root->right=deletenode(root->right,item);
	else
	{
		//if the node is with only one child or no child
		if(root->left==0)
		{
			struct node*temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==0)
		{
			struct node*temp=root->left;
			free(root);
			return temp;
		}
		//if the node has two child node
		struct node*temp=minValueNode(root->right);
		
		//place the inorder key
		root->data=temp->data;
		
		//delete the inorder successor
		root->right=deletenode(root->right,temp->data);
	}
	printf("node deleted\n");
	return root;
}

void search(struct node*root,int item)
{
	if(root==0)return;
	if(item==root->data)
	{
		printf("element %d found\n",root->data);
		return;
	}
	else if(item<root->data)
	search(root->left,item);
	else if(item>root->data)
	search(root->right,item);
	else
	{
		printf("element not found\n");
		return;
	}
}
int main()
{
	int ch;
	do
	{
		printf("\nenter 0 to exit\nenter 1 to insert\nenter 2 to print\nenter 3 to delete\nrnter 4 to search\n");
    	scanf("%d",&ch);
    	switch(ch)
    	{
    		case 0:printf("PROGRAM TERMINATED\n");
    		       exit(0);
			       break;
		    case 1:printf("enter your data:\n");
                   scanf("%d",&item);
                   root=insert(root,item);
                   break;
            case 2:printf("inorder traversal:\n");
				   inorder(root);
				   break;
		 	case 3:printf("enter your data to be deleted:\n");
                   scanf("%d",&item);
			 	   deletenode(root,item);
				   break;
		    case 4:printf("enter your data to be searched:\n");
                   scanf("%d",&item);
			 	   search(root,item);
				   break;					  
			default:
			        printf("ENTER VALID CHOICE!!\n");
				    return;
				    break;		
		}		 
	}while(ch!=0);
}


















