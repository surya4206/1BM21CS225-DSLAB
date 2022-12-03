#include<stdio.h>
#include<stdlib.h>
#define size 3
int queue[size],front=-1,rear=-1,item,i;
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
                   if(del!=0)
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
    if((front==0 && rear==size-1)||(front==rear+1))
    {
        printf("Queue is full\n");
        return;
    }
    else
    {
        printf("Enter the element:");
        scanf("%d",&item);
        if(front==-1 && rear==-1)
        {
            front=0;
            rear=0;
        }
        else
            rear=(rear+1)%size;
        queue[rear]=item;
    }
}
int delete()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty\n");
        return;
    }
    int d=queue[front];
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
        front=(front+1)%size;
    return d;
}
void display()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty\n");
        return;
    }
    if(front<=rear)
    {
        for(i=front;i<=rear;i++)
            printf("%d\t",queue[i]);
    }
    else
    {
        for(i=front;i<size;i++)
            printf("%d\t",queue[i]);
        for(i=0;i<=rear;i++)
            printf("%d\t",queue[i]);
        printf("\n");
    }
}
