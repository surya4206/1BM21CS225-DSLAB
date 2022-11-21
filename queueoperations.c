#include<stdio.h>
#include<stdlib.h>
#define size 3
int queue[size],rear=-1,item;
void insert();
int delete();
void display();
void main()
{
    int choice,del;
    while(1)
    {
        printf("1.Insert 2.Delete 3.Display 4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:insert();
                   break;
            case 2:del=delete();
                   printf("Deleted element=%d\n",del);
                   break;
            case 3:display();
                   break;
            case 4:exit(0);
                   break;
            default:printf("Wrong choice\n");
        }
    }
}
void insert()
{
    if(rear==size-1)
    {
        printf("Queue is full\n");
        return;
    }
    else
    {
        printf("Enter the element:");
        scanf("%d",&item);
        rear++;
        queue[rear]=item;
    }
}
int delete()
{
    int d;
    if(rear==-1)
    {
        printf("Queue is empty\n");
        return;
    }
    else
    {
        d=queue[0];
        int i;
        for(i=0;i<rear;i++)
            queue[i]=queue[i+1];
        rear--;
        return d;
    }
}
void display()
{
    int i;
    if(rear==-1)
    {
        printf("Queue is empty\n");
        return;
    }
    else
    {
        printf("Queue contents:");
        for(i=0;i<=rear;i++)
            printf("%d\n",queue[i]);
    }
}
