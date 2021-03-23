//Here we are maintaining head and tail pointer

#include<stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct Node *head=NULL;
struct Node *tail=NULL;

void Create()
{
  struct Node *new;
  new=(struct Node*)malloc(sizeof(struct Node));
  printf("Enter the data\n");
  scanf("%d",&new->data);
  if(head==NULL)
  {
    head=tail=new;
  }
  else
  {
    tail->next=new;
    tail=new;
  }
//  printf("%d",head->data);
  tail->next=head;
//  printf("%d",tail->next->data);
}

void Display()
{
  struct Node *temp;
  temp=head;
  while(temp->next!=head)
  {
    printf("%d->",temp->data);
    temp=temp->next;
  }
  printf("%d",temp->data);
}

void main()
{
  int ch;
  printf("\nEnter the choice \n1.Create\n2.Display\n 0.Exit\n");
  scanf("%d",&ch);
  switch(ch)
  {
    case 1:
      Create();
      main();
    case 2:
      Display();
      main();
    case 0:
      exit(0);
  }
}
