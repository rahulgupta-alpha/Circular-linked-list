#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct Node *head=NULL;

void Create()
{
  struct Node *new,*temp;
  new=(struct Node*)malloc(sizeof(struct Node));
  printf("Enter the data\n");
  scanf("%d",&new->data);
  if(head==NULL)
  {
    head=temp=new;
    new->next=head;
  }
  else
  {
    temp=head;
    while(temp->next!=head)
    {
      temp=temp->next;
    }
    printf("%d",head->data);//this is to verify Linked list is circular or not
    temp->next=new;
    new->next=head;
    printf("%d",new->next->data);//this is to verify Linked list is circular or not
  }
}

void Display()
{
  struct Node *temp;
  temp=head;
  while(temp->next!=head)
  {
    printf("%d",temp->data);
    temp=temp->next;
  }
  printf("%d",temp->data);
}

void main()
{
  int ch;
  printf("\nEnter the choice\n 1.Create\n 2.Display\n 0.Exit");
  scanf("%d",&ch);
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
