#include<stdio.h>
#include<stdlib.h>
struct NODE
{
	struct NODE *llink;
	int data;
	struct NODE *rlink;
};
typedef struct NODE node;
node *start=NULL,*curr,*new,*temp;
void create()
{
	start=(node*)malloc(sizeof(node));
	printf("Enter element:");
	scanf("%d",&start->data);
	start->llink=NULL;
	curr=start;
	while(1)
	{
		int choice;
	    printf("Do you want to add an element? press 1 for yes\n");
        scanf("%d", &choice);
        if(choice)
        {
            new = (node*)malloc(sizeof(node));
            curr->rlink=new;
            new->llink=curr;
            printf("Enter the element:");
            scanf("%d",&new->data);
            curr=new;
   		 }
   		else
   		{
   		 	curr->rlink=NULL;
   		 	break;
		}
}
}
void insert_beg()
{
	new=(node*)malloc(sizeof(node));
	printf("Enter an element:");
	scanf("%d",&new->data);
	if(start==NULL)
	{
		new->llink=NULL;
		new->rlink=NULL;
		start=new;
		return;
	}
	new->rlink=start;
	start->llink=new;
	new->llink=NULL;
	start=new;
}
void delete_ele()
{
    node *temp;
    int ele;
	if(start==NULL)
	{
		printf("Linked list is empty\n");
		return;
	}
	printf("Enter element to be deleted:");
	scanf("%d",&ele);
	if(start->data==ele)
	{
		temp=start;
		start=start->rlink;
		start->llink=NULL;
		free(temp);
		return;
	}
	temp=start;
	while(temp->rlink!=NULL&&temp->data!=ele)
		temp=temp->rlink;
	if(temp->data==ele&&temp->rlink==NULL)
	{
		temp->llink->rlink=NULL;
		free(temp);
		return;
	}
	if(temp->data==ele&&temp->rlink!=NULL)
	{
		temp->llink->rlink=temp->rlink;
		temp->rlink->llink=temp->llink;
		free(temp);
		return;
	}
	printf("Element not found\n");
}
void display()
{
	if(start==NULL)
	{
		printf("Linked list is empty\n");
		return;
	}
	temp=start;
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->rlink;
	}
}
void main()
{
    int choice;
    printf("1.CREATE\n2.INSERT AT BEGINING\n3.DELETE SPECIFIC ELEMENT\n4.DISPLAY\n5.EXIT\n");
    while(1)
    {
        printf("Enter choice:\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: create();
                break;
            case 2: insert_beg();
                break;
            case 3: delete_ele();
                break;
            case 4:display();
            	break;
            case 5:exit(0);
            	break;
            default:printf("Invalid choice\n");
        }
    }
}