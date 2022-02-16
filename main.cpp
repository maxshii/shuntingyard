/*
 * An implementation of the Shunting Yard Algorithm that uses stack, queue, and tree data structures.
 * Author: Max Shi
 * Last modified: 2/14/2022
 */
#include <iostream>
#include "binarynode.h"
using namespace::std;

//struct for a node of a linear linked list
struct lnode
{
  char data;
  lnode* next;
  lnode(char data)
  {
    data = data;
    next = NULL;
  }
};

struct stack
{
  lnode* head; //top of stack
  stack()
  {
    head = NULL;
  }
};

//struct for a node of a linear linked list that contains a pointer to a binary tree node
struct lnodeb
{
  bnode* data;
  lnode* next;

  lnodeb(bnode* data)
  {
    data = data;
    next = NULL;
  }
};

struct operandStack
{
  lnodeb* head; //top of stack
  operandStack()
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

//functions for stack holding characters
void push(lnode* &head, char data);
char pop(lnode* &head);
char peek(lnode* head);

//functions for stack holding pointers to binary tree nodes
void push(lnodeb* &head, char data);
char pop(lnodeb* &head);
char peek(lnodeb* head);

void enqueue(lnode* &head, lnode* &tail, char data);
char dequeue(lnode* &head);
void printList(lnode* head); 
bnode* buildTree(queue math);


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


//adds to top of stack
void push(lnode* &head, char data)
{
  lnode* lnode = new struct lnode(data);
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
  lnode* lnode = new struct lnode(data);
  if(head == NULL)
    {
      head = lnode;
    }
  else if(tail == NULL)
    {
      tail = lnode;
      head->next = tail;
    }
  else
    {
      //tail's next points to the new node and then tail points to the new node
      tail->next = lnode;
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
/*
bnode* buildTree(queue math)
{
  bnode* operand[10]
}*/