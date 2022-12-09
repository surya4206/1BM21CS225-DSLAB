#include<stdio.h>
#include<stdlib.h>
struct NODE
{
    int data;
    struct NODE *link;
};
typedef struct NODE node;
void create()
{
    char ch;
    node *start,*new,*curr;
    start=NULL;
    new=(node *)malloc(sizeof(node));
    printf("Enter the element:");
    scanf("%d",&start->data);
    while(1)
    {
        printf("Add another element?");
        scanf("%c",&ch);
        if(ch=='y'||ch=='Y')
        {
            new=(node *)malloc(sizeof(node));
            printf("Enter the element:");
            scanf("%d",&new->data);
            curr->link=new;
            curr=new;
        }
        else
        {
            curr->link=NULL;
            break;
        }
    }
}
void display()
{
    node *temp;
    if(start==NULL)
    {
        printf("Linked list is empty");
        return;
    }
    temp=start;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->link;
    }
}
void main()
{
    create();
    display();
}