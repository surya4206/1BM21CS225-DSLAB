#include<stdio.h>
#include<stdlib.h>
struct node
{
	int key;
	struct node *left,*right;
};
struct node* newnode(int item)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->key=item;
	temp->left=temp->right=NULL;
	return temp;
}
struct node* insert(struct node* node,int key)
{
	if(node==NULL)
		return newnode(key);
	if(key<node->key)
		node->left=insert(node->left,key);
	else
		node->right=insert(node->right,key);
	return node;
}
struct node* minvaluenode(struct node* node)
{
	struct node* curr=node;
	while(curr&&curr->left!=NULL)
		curr=curr->left;
	return curr;
}
struct node* deletenode(struct node* root,int key)
{
	if(root==NULL)
	{
		printf("Empty");
		return root;
	}
	if(root->key>key)
		root->left=deletenode(root->left,key);
	else if(root->key<key)
		root->right=deletenode(root->right,key);
	else
	{
		if(root->left==NULL)
		{
			struct node* temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			struct node* temp=root->left;
			free(root);
			return temp;
		}
		struct node* temp=minvaluenode(root->right);
		root->key=temp->key;
		root->right=deletenode(root->right,temp->key);
	}
	return root;
}
void inorder(struct node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d\t",root->key);
		inorder(root->right);
	}
}
void preorder(struct node* node)
{
	if(node!=NULL)
	{
		printf("%d\t",node->key);
		preorder(node->left);
		preorder(node->right);
	}
}
void postorder(struct node* node)
{
	if(node!=NULL)
	{
		postorder(node->left);
		postorder(node->right);
		printf("%d\t",node->key);
	}
}
int main()
{
	struct node* root=NULL;
	int n,ele;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		printf("Enter element:");
		scanf("%d",&ele);
		root=insert(root,ele);
	}
	printf("\nInorder traversal of the tree:");
	inorder(root);
	printf("\nEnter element to delete:");
	scanf("%d",&ele);
	deletenode(root,ele);
	printf("\nInorder traversal of the tree:");
	inorder(root);
	printf("\nPreorder traversal of the tree:");
	preorder(root);
	printf("\nPostorder traversal of the tree:");
	postorder(root);
}
