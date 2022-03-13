/***************************************************************************
****************************************************************************
Name - Madhusudan Chand
Reg_No. - VB-3454 2020-21
Date - 11.01.2022
Prog - Implement ternary tree and its traversals.
****************************************************************************
****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left,*mid,*right;
};

struct node *root;
struct node *create();
void preorder(struct node *mad);
void inorder_1(struct node *mad);
void inorder_2(struct node *mad);
void postorder(struct node *mad);
int main()
{
	printf("Enter the root node : \n");
	root=create();
	printf("Preorder traversal of the ternary tree is : \n");
	preorder(root);
	printf("\nInorder_1 traversal of the ternary tree is : \n");
	inorder_1(root);
	printf("\nInorder_2 traversal of the ternary tree is : \n");
	inorder_2(root);
	printf("\nPostorder traversal of the ternary tree is : \n");
	postorder(root);
	return 0;
}

struct node *create()
{
	int item;
	struct node *ptr;
	ptr=(struct node*)malloc(sizeof(struct node));
	if(ptr==NULL)
	printf("Insufficient memeory.\n");
	else
	{
		printf("Enter the data : \n");
		scanf("%d",&item);
		ptr->data=item;
		
		if(item==0)
		return NULL;

		printf("Enter the left node of %d(if no press 0) : \n",ptr->data);
		ptr->left=create();
		
		printf("Enter the middle node of %d(if no press 0) : \n",ptr->data);
		ptr->mid=create();
		
		printf("Enter the right node of %d(if no press 0) : \n",ptr->data);
		ptr->right=create();
	}
	return ptr;
}

void preorder(struct node *mad)
{
	if(mad==NULL)
	return;
	else
	{
		printf("%d\t",mad->data);
		preorder(mad->left);
		preorder(mad->mid);
		preorder(mad->right);
	}
}

void inorder_1(struct node *mad)
{
	if(mad==NULL)
	return;
	else
	{
		inorder_1(mad->left);
		printf("%d\t",mad->data);
		inorder_1(mad->mid);
		inorder_1(mad->right);
	}
}

void inorder_2(struct node *mad)
{
	if(mad==NULL)
	return;
	else
	{
		inorder_2(mad->left);
		inorder_2(mad->mid);
		printf("%d\t",mad->data);
		inorder_2(mad->right);
	}
}

void postorder(struct node *mad)
{
	if(mad==NULL)
	return;
	else
	{
		postorder(mad->left);
		postorder(mad->mid);
		postorder(mad->right);
		printf("%d\t",mad->data);
	}
}
