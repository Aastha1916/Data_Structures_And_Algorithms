#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node*left,*right;
};
struct node*root;

struct node*create()
{
	int data,ch;
	struct node*temp;
	temp=(struct node*)malloc(sizeof (struct node));
	printf("PRESS\n 1:TO ADD\n0:TO RETURN\nENTER YOUR CHOICE\n");
	scanf("%d",&ch);
	if(ch==0)
	return ;
	else if(ch==1)
	{
	printf("\nEnter the data:\n");
	scanf("%d",&data);
	temp->data=data;
	printf("Enter the left child of %d\n",data);
	temp->left=create();
	printf("Enter the right child of %d\n",data);
	temp->right=create();
	}
	else
	{
		printf("INVALID ARGUMENT\n");
		return;
	}
	return temp;
}

/*
 First recursively deletes left and right subtree 
 then delete root node 
*/
void deleteTree(struct node *root){
    if(root == NULL)
        return;
    /* Delete Left sub-tree */
    deleteTree(root->left);
    /* Delete right sub-tree */
    deleteTree(root->right);
     
    /* At last, delete root node */
    printf("Deleteing Node : %d\n", root->data);
    free(root);
     
    return;
}

void inOrderTraversal(struct node*root)
{
	if(root==0)
	{
	  //	printf("......INVALID....\nCREATE TREE FIRST");
		return;
	}
	inOrderTraversal(root->left);
	printf("%d ->",root->data);
	inOrderTraversal(root->right);	
}

void preOrderTraversal(struct node*root)
{
	if(root==0)
	{
	//	printf("......INVALID....\nCREATE TREE FIRST");
		return;
	}
	printf("%d ->",root->data);
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);	
}

void postOrderTraversal(struct node*root)
{
	if(root==0)
	{
	//	printf("......INVALID....\nCREATE TREE FIRST");
		return;
	}
	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	printf("%d ->",root->data);	
}



void main()
{
	int choice;
	do{
		printf("\nPRESS:\n0.to exit\n1.to create new tree\n2.inOrder traversal\n3.preOrder traversal\n4.postOrder traversal\n5.delete a node\nENTER YOUR CHOICE\n");
		scanf("%d",&choice);
		switch(choice)
		{
		case 0:printf("PROGRAM TERMINATED\n");
		 	   exit(0);break;
		case 1: root=create();
	  				break;
		case 2:	inOrderTraversal(root);
				break;
		case 3: preOrderTraversal(root);
				break;
		case 4:	postOrderTraversal(root);
				break;
		case 5: deleteTree(root);
				break;
		default:printf("INVALID ARGUMENT!!\n");
			    	break;
   		}
	}while(choice!=0);
		
}
	
	


