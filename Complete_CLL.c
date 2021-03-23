//maintaining only tail pointer

#include<stdio.h>
#include<stdlib.h>
int Length_Of_CLL();
struct Node
{
  int data;
  struct Node *next;
};
struct Node *tail=NULL;
void Insertion_at_beginning()
{
  struct Node *new;
  new=(struct Node*)malloc(sizeof(struct Node));
  printf("Enter the data\n");
  scanf("%d",&new->data);
  new->next=NULL;
  if(tail==NULL)
  {
    tail=new;
    tail->next=new;
  }
  else
  {
    new->next=tail->next;
    tail->next=new;
  }
  printf("first_node :%d\n",tail->next->data);
}
void Insertion_at_end()
{
  struct Node *new;
  new=(struct Node*)malloc(sizeof(struct Node));
  printf("Enter the data\n");
  scanf("%d",&new->data);
  new->next=NULL;
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
  printf("first_node: %d",tail->next->data);
}
void Insertion_at_specified_pos()
{
  struct Node *new,*temp;
  int i=1,l,pos;
  printf("Enter the position for insertion\n");
  scanf("%d",&pos);
  l=Length_Of_CLL();
  if(pos<0||pos>l)
  {
    printf("Invalid position\n");
  }
  else if(pos==1)
  {
    Insertion_at_beginning();
  }
  else if(pos==l)
  {
    Insertion_at_end();
  }
  else
  {
    new=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter the data\n");
    scanf("%d",&new->data);
    new->next=NULL;
    temp=tail->next;
    while(i<pos-1)
    {
      temp=temp->next;
      i++;
    }
    new->next=temp->next;
    temp->next=new;
  }
}
void Deletion_from_beginning()
{
  struct Node *temp;
  if(tail!=NULL)
  {
    temp=tail->next;
    if(temp->next==temp)
    {
      tail=NULL;
      free(temp);
    }
    else
    {
      tail->next=temp->next;
      free(temp);
    }
  }
  else
  {
    printf("List Is Empty\n");
  }
}
void Deletion_from_end()
{
  struct Node *current,*previous;
  if(tail!=NULL)
  {
    current=tail->next;
    if(current->next==tail)
    {
      tail=NULL;
      free(current);
    }
    else
    {
      while(current->next!=tail->next)
      {
        previous=current;
        current=current->next;
      }
      previous->next=tail->next;
      tail=previous;
      free(current);
    }
  }
  else
  {
    printf("Linked List Is Empty\n");
  }
}
void Delete_from_spec_pos()
{
  struct Node *temp,*prev;
  int pos,i=1,l;
  printf("Enter the position\n");
  scanf("%d",&pos);
  l=Length_Of_CLL();
  if(pos<0||pos>l)
  {
    printf("Invalid position\n");
  }
  else if(pos==1)
  {
    Deletion_from_beginning();
  }
  else if(pos==l)
  {
    Deletion_from_end();
  }
  else
  {
    temp=tail->next;
    while(i<pos-1)
    {
      temp=temp->next;
      i++;
    }
    prev=temp->next;
    temp->next=prev->next;
    free(prev);
  }
}
void Display()
{
  struct Node *temp;
  if(tail==NULL)
  {
    printf("Linked List Is Empty\n");
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
int Length_Of_CLL()
{
  struct Node *temp;
  int l=1;
  if(tail==NULL)
  {
    printf("Linked List Is Empty\n");
  }
  else
  {
    temp=tail->next;
    while(temp->next!=tail->next)
    {
      l++;
      temp=temp->next;
    }
    printf("Length_Of_CLL:- %d\n",l);
    return l;
  }
}

void first_node()
{
  printf("First Node:- %d",tail->next->data);
}
void Reverse()
{
  struct Node *curr,*prev,*temp;
  curr=tail->next;
  temp=curr->next;
  if(tail==NULL)
  {
    printf("List Is Empty\n");
  }
  else
  {
    while(curr!=tail)
    {
      prev=curr;
      curr=temp;
      temp=curr->next;
      curr->next=prev;
    }
    temp->next=tail;
    tail=temp;
  }
}
void main()
{
  int ch;
  printf("\nEnter your choice\n1.Insertion_at_beginning\n2.Display\n3.Insertion_at_end\n4.Length_Of_CLL\n5.Insertion_at_specified_pos\n6.Deletion_from_beginning\n7.Deletion_from_end\n8.Delete_from_spec_pos\n9.First Node\n 10Reverse the list\n0.Exit\n");
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
      Insertion_at_end();
      main();
    case 4:
      Length_Of_CLL();
      main();
    case 5:
      Insertion_at_specified_pos();
      main();
    case 6:
      Deletion_from_beginning();
      main();
    case 7:
      Deletion_from_end();
      main();
    case 8:
      Delete_from_spec_pos();
      main();
    case 9:
      first_node();
      main();
    case 10:
      Reverse();
      main();
    case 0:
      exit(0);
  }
}
