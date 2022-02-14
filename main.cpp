/*
 * An implementation of the Shunting Yard Algorithm that uses stack, queue, and tree data structures.
 * Author: Max Shi
 * Last modified: 2/14/2022
 */
#include <iostream>
using namespace::std;

//struct for a node of a linear linked list
struct lnode
{
  char data;
  lnode* next;
  
};

struct stack
{
  lnode* head; //top of stack
  stack()
  {
    head = NULL;
  }
};

struct queue
{
  lnode* head; //where nodes are dequeued
  lnode* tail; //where nodes are enqueued
  queue()
  {
    head = NULL;
    tail = NULL;
  }
};

lnode* newLnode(char data);
void push(lnode* &head, char data);
char pop(lnode* &head);
char peek(lnode* head);
void enqueue(lnode* &head, lnode* &tail, char data);
char dequeue(lnode* &head);
void printList(lnode* head); 

int main()
{
  queue q;
  enqueue(q.head, q.tail, '1');
  enqueue(q.head, q.tail, '2');
  enqueue(q.head, q.tail, '3');
  printList(q.head);
  cout<<'\n';
  dequeue(q.head);
  printList(q.head);
}

//creates new lnode
lnode* newLnode(char data)
{
  lnode* l = new lnode();
  l->data = data;
  l->next = NULL;
  return l;
}

//adds to top of stack
void push(lnode* &head, char data)
{
  lnode* lnode = newLnode(data);
  lnode->next = head; //next points to current head
  head = lnode; //head now points to the new node
}

//returns top of stack and deletes it
char pop(lnode* &head)
{
  if(head == NULL)
    {
      return '\0';
    }

  //move head to next and return data in old head
  char data = head->data;
  lnode* temp = head;
  head = head->next;
  delete temp;
  return data;
}

//returns value at the top of stack
char peek(lnode* head)
{
  return head->data;
}

//adds to queue
void enqueue(lnode* &head, lnode* &tail, char data)
{
  lnode* l = newLnode(data);

  if(head == NULL)
    {
      head = l;
    }
  else if(tail == NULL)
    {
      tail = l;
      head->next = tail;
    }
  else
    {
      //tail's next points to the new node and then tail points to the new node
      tail->next = l;
      tail = tail->next;
    }
}

//returns front of queue and deletes it
char dequeue(lnode* &head)
{
  return pop(head);
}

void printList(lnode* head)
 {
   if(head != NULL)
     {
       cout << head->data << " ";
       printList(head->next);
     }
 }
