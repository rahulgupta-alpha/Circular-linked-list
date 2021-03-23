//maintaining head and tail pointer
#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct Node *head =NULL;
struct Node *tail =NULL;

void Insertion_at_beginning()
{
  struct Node *new;
  new=(struct Node*)malloc(sizeof(struct Node));
  printf("Enter the data\n");
  scanf("%d",&new->data);
  if(head==NULL)
  {
    head=tail=new;
    //tail->next=new;
  }
  else
  {
    new->next=head;
  //  tail->next=new;
    head=new;
  }
  tail->next=head;
}

void Insertion_at_end()
{
  struct Node *new;
  //new=(struct Node*)malloc(sizeof(struct Node));
  if(head==NULL)
  {
    Insertion_at_beginning();
  }
  else
  {
    new=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter the data\n");
    scanf("%d",&new->data);
    tail->next=new;
    new->next=head;
    tail=new;
  }
}
int Length_Of_CLL()
{
  struct Node *temp;
  temp=head;
  int l=1;
  while(temp->next!=head)
  {
    l++;
    temp=temp->next;
  }
  //printf("%d",l);
  return l;
}
void Insertion_before_specified_pos()
{
  int position,i=1,l;
  struct Node *new,*temp;
  printf("Enter the position\n");
  scanf("%d",&position);
  l=Length_Of_CLL();
  if(position<0||position>l)
  {
    printf("Invalid position\n");
  }
  else if(position==1)
  {
    Insertion_at_beginning();
  }
  else if(position==l)
  {
    Insertion_at_end();
  }
  else
  {
    new=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter the data\n");
    scanf("%d",&new->data);
    temp=head;
    while(i<position-1)
    {
      temp=temp->next;
      i++;
    }
    new->next=temp->next;
    temp->next=new;
  }

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
  int ch,l;
  printf("\nEnter your choice\n1.Insertion_at_beginning\n2.Display\n3.Length_Of_CLL\n4.Insertion_at_end\n5.Insertion_at_specified_pos\n0.Exit\n");
  scanf("%d",&ch);
  switch(ch)
  {
    case 1:
      Insertion_at_beginning();
      main();
    case 2:
      Display();
      main();
    case 3:
      l=Length_Of_CLL();
      printf("Length of Linked List :- %d",l);
      main();
    case 4:
      Insertion_at_end();
      main();
    case 5:
      Insertion_before_specified_pos();
      main();
    case 0:
      exit(0);
  }
}
