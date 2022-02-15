/*
 * An implementation of the Shunting Yard Algorithm that uses stack, queue, and tree data structures.
 * Author: Max Shi
 * Last modified: 2/14/2022
 */
#include <iostream>
#include "binarynode.h"
using namespace::std;

union data {
    char math;
    bnode* bnodePtr;
};

//struct for a node of a linear linked list that stores a char
struct lnode
{
  data data;
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

lnode* newLnode(data newData);
void push(lnode* &head, data newData);
auto pop(lnode* &head);
auto peek(lnode* head);
void enqueue(lnode* &head, lnode* &tail, data newData);
auto dequeue(lnode* &head);
void printList(lnode* head); 
bnode* infixToTree(queue expression);
bnode* postfixToTree(queue expression);
bnode* prefixToTree(queue expression);

int main()
{
  queue q;

  union data 
  data a.math = '1';
    data a.math = '1';

  enqueue(q.head, q.tail, );
  enqueue(q.head, q.tail, '2');
  enqueue(q.head, q.tail, '3');
  printList(q.head);
  cout<<'\n';
  postfixToTree(q);

  printList(q.head);
}

//creates new lnode
lnode* newLnode(data newData)
{
  lnode* l = new lnode();
  l->data = newData;
  l->next = NULL;
  return l;
}

//adds to top of stack
void push(lnode* &head, char d)
{
  lnode* lnode = newLnode(d);
  lnode->next = head; //next points to current head
  head = lnode; //head now points to the new node
}

//returns top of stack and deletes it
auto pop(lnode* &head)
{
  if(head == NULL)
    {
      return '\0';
    }

  //move head to next and return data in old head
  char data = head->d.c;
  lnode* temp = head;
  head = head->next;
  delete temp;
  return data;
}

//returns value at the top of stack
auto peek(lnode* head)
{
  return head->data.c;
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
auto dequeue(lnode* &head)
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

bnode* infixToTree(queue expression)
{
  
}

bnode* postfixToTree(queue expression)
{
  cout << "Postfix expression: ";
  printList(expression.head);
  cout << '\n';

  stack s;
  while(expression.head != NULL)
    {
      char symbol = dequeue(expression.head);
      if(isdigit(symbol) != 0)
      {
        bnode* n = new bnode();
        push(s.head)
      }
    }
}

bnode* prefixToTree(queue expression)
{
  
}