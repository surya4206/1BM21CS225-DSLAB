#include<stdio.h>
#include<stdlib.h>
struct NODE
{
    int data;
    struct NODE *link;
};
typedef struct NODE node;
node *front=NULL,*rear=NULL,*new=NULL;
void disp()
{
    node *temp;
    if(front==NULL)
    {
        printf("Empty");
        return;
    }
    temp=front;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->link;
    }
}
void ins_beg()
{
    new=(node*)malloc(sizeof(node));
    printf("Enter element:");
    scanf("%d",&new->data);
    if(front==NULL)
    {
        front=new;
        rear=new;
        new->link=NULL;
        return;
    }
    new->link=front;
    front=new;
}
void ins_end()
{
    node *temp;
    temp=rear;
    new=(node*)malloc(sizeof(node));
    printf("Enter element:");
    scanf("%d",&new->data);
    if(front==NULL)
    {
        front=new;
        rear=new;
        new->link=NULL;
        return;
    }
    new->link=NULL;
    temp->link=new;
    temp=temp->link;
    rear=temp;
}
void del_beg()
{
    node *temp;
    temp=front;
    if(front==NULL)
    {
        printf("Empty");
        return;
    }
    front=front->link;
    free(temp);
}
void stackop()
{
    int c1;
    while(1)
    {
        printf("\n1.Push 2.Pop 3.Display 4.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&c1);
        switch(c1)
        {
            case 1:ins_beg();
                   break;
            case 2:del_beg();
                   break;
            case 3:disp();
                   break;
            case 4:exit(0);
                   break;
            default:printf("Wrong choice!");
        }
    }
}
void queueop()
{
    int c1;
    while(1)
    {
        printf("\n1.Insert 2.Delete 3.Display 4.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&c1);
        switch(c1)
        {
            case 1:ins_end();
                   break;
            case 2:del_beg();
                   break;
            case 3:disp();
                   break;
            case 4:exit(0);
                   break;
            default:printf("Wrong choice!");
        }
    }
}
void main()
{
    int c1;
    printf("1.Stack 2.Queue");
    printf("\nEnter your choice:");
    scanf("%d",&c1);
    switch(c1)
    {
        case 1:stackop();
               break;
        case 2:queueop();
               break;
        default:printf("Wrong Choice!");
    }
}
