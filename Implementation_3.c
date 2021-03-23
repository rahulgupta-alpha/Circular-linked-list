//Implementation of circular linked list by maintaining only tail pointer

#include<stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct Node *tail=NULL;

void Create()
{
  struct Node *new;
  new=(struct Node*)malloc(sizeof(struct Node));
  printf("Enter te data\n");
  scanf("%d",&new->data);
  if(tail==NULL)
  {
    tail=new;
    tail->next=new;
  }
  else
  {
    new->next=tail->next;
    tail->next=new;
    tail=new;
  }
}

void Display()
{
  struct Node *temp;
  temp=(struct Node*)malloc(sizeof(struct Node));
  if(tail==NULL)
  {
    printf("List Is Empty\n");
  }
  else
  {
    temp=tail->next;
    while(temp->next!=tail->next)
    {
      printf("%d->",temp->data);
      temp=temp->next;
    }
    printf("%d",temp->data);
  }
}

void main()
{
  int ch;
  printf("\nEnter the choice\n1.Create\n2.Display\n0.Exit");
  scanf("%d",&ch );
  switch(ch)
  {
    case 1:
      Create();
      main();
    case 2:
      Display();
      main();
    case 3:
      exit(0);
  }
}
