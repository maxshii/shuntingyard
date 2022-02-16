/*
 * An implementation of the Shunting Yard Algorithm that uses stack, queue, and tree data structures.
 * Author: Max Shi
 * Last modified: 2/14/2022
 */
#include <iostream>
using namespace::std;



struct stack
{
  lnode* head; //top of stack
  stack()
  {
    head = NULL;
  }
};



lnode* newLnode(char data);
void push(lnode* &head, char data);
char pop(lnode* &head);
char peek(lnode* head);

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