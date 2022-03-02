/*
 * An implementation of the Shunting Yard Algorithm that uses stack, queue, and tree data structures.
 * Author: Max Shi
 * Last modified: 2/18/2022
 */
#include <iostream>
#include <cctype>
#include <cstring>
#include "binarynode.h"
using namespace::std;

//struct for a node of a linear linked list
struct lnode
{
  char data;
  lnode* next;
};

//struct containing pointer to top of stack, nodes store characters
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
  lnodeb* next;
};

//struct containing pointer to top of stack, nodes store binary tree nodes
struct stackb
{
  lnodeb* head; //top of stack
  stackb()
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
lnode* newLnode(char data);
void push(lnode* &head, char data);
char pop(lnode* &head);
char peek(lnode* head);

//functions for stack holding pointers to binary tree nodes
lnodeb* newLnodeb(bnode* data);
void push(lnodeb* &head, bnode* data);
bnode* pop(lnodeb* &head);
bnode* peek(lnodeb* head);

//functions for queue
void enqueue(lnode* &head, lnode* &tail, char data);
char dequeue(lnode* &head);
void printList(lnode* head); 

//functions for binary tree
bnode* buildTree(queue math);
void printPost(bnode* tree);
void printPre(bnode* tree);
void printIn(bnode* tree);

queue inToPost(queue math);
int precedence(char num);

int main()
{
  //reads a mathematical expression entered with infix notation, using spaces between each token. Outputs postfix form and lets user choose to output infix, postfix, or prefix.
  while(true)
    {
      cout << "Enter expression:\n";
      char input[80];
      cin.getline(input, 80);
      queue math;
      for(int i = 0; i<strlen(input); i++)
        {
          if(input[i] != ' ')
          {
            enqueue(math.head, math.tail, input[i]);
          }
        }
      math = inToPost(math);
      printList(math.head);
      bnode* tree = buildTree(math);

      cout << "\nChoose output (infix, postfix, prefix):\n";
      cin.getline(input, 80);
      if(strcmp(input, "infix") == 0)
        printIn(tree);
      if(strcmp(input, "postfix") == 0)
        printPost(tree);
      if(strcmp(input, "prefix") == 0)
        printPre(tree);

      cout << '\n';
    }

}

lnode* newLnode(char data)
{
  lnode* node = new lnode();
  node->data = data;
  node->next = NULL;
  return node;
}

lnodeb* newLnodeb(bnode* data)
{
  lnodeb* node = new lnodeb();
  node->data = data;
  node->next = NULL;
  return node;
}

//adds to top of stack
void push(lnode* &head, char data)
{
  lnode* lnode = newLnode(data);
  lnode->next = head; //next points to current head
  head = lnode; //head now points to the new node
}

void push(lnodeb* &head, bnode* data)
{
  lnodeb* node = newLnodeb(data);
  node->next = head; //next points to current head
  head = node; //head now points to the new node
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
bnode* pop(lnodeb* &head)
{
  if(head == NULL)
    {
      return NULL;
    }

  //move head to next and return data in old head
  bnode* data = head->data;
  lnodeb* temp = head;
  head = head->next;
  delete temp;
  return data;
}

//returns value at the top of stack
char peek(lnode* head)
{
  if(head != NULL)
    return head->data;
  return '\0';
}

bnode* peek(lnodeb* head)
{
  if(head->data != NULL)
  {
    return head->data;
    }
  return NULL;
}

//adds to queue
void enqueue(lnode* &head, lnode* &tail, char data)
{
  lnode* lnode = newLnode(data);
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
  if(head != NULL)
  {
    return pop(head);
  }
  return '\0';
}

void printList(lnode* head)
 {
   if(head != NULL)
     { 
       cout << head->data << " ";
       printList(head->next);
     }
 }

//builds a tree using a queue of mathematical symbols in postfix form. Follows steps from https://en.wikipedia.org/wiki/Binary_expression_tree
bnode* buildTree(queue math)
{
  stackb stack;
  char symbol = dequeue(math.head);
  while(symbol != '\0')
    {
      //if symbol is an integer, create a binary node containing the symbol and push it to stack
      if(isdigit(symbol) != 0) 
      {
        bnode* tree = new bnode(symbol);
        push(stack.head, tree);
      }
      //if the symbol is an operator, pop twice from the stack and create a new bnode with symbol as data and the popped as left and right
      else if(symbol == '+' || symbol == '-' || symbol == '/' || symbol == '*' || symbol == '^')
      {
        bnode* T1 = pop(stack.head);
        bnode* T2 = pop(stack.head);
        bnode* tree = new bnode(symbol);
        tree->left = T2;
        tree->right = T1;
        push(stack.head, tree);
      }
      symbol = dequeue(math.head);
    }
  return pop(stack.head);
}

//print left subtree, right subtree, then operator
void printPost(bnode* tree)
{
  if(tree != NULL)
  {
    printPost(tree->left);
    printPost(tree->right);
    cout << tree->data;
  }
}

//print operator, then left subtree, then right subtree
void printPre(bnode* tree)
{
  if(tree != NULL)
  {
    cout << tree->data;
    printPre(tree->left);
    printPre(tree->right);
  }
}

//print parantheses when there is an operator, then left subtree, operator, right subtree, then closing parantheses
void printIn(bnode* tree)
{
   if(tree != NULL)
   {
     if(tree->data == '+' || tree->data == '-' || tree->data == '/' || tree->data == '*' || tree->data == '^') //print parantheses if operator
     {
       cout << '(';
     }
     printIn(tree->left);
     cout << tree->data;
     printIn(tree->right);
     if(tree->data == '+' || tree->data == '-' || tree->data == '/' || tree->data == '*' || tree->data == '^')
     {
       cout << ')';
     }
   }  
}

//converts infix to postfix using the shunting yard algorithm. Follows steps from https://en.wikipedia.org/wiki/Shunting-yard_algorithm
queue inToPost(queue math)
{
  queue output;
  stack operatorStack;
  char symbol = dequeue(math.head);
  while(symbol != '\0')
  {
    if(isdigit(symbol) != 0)
    {
      enqueue(output.head, output.tail, symbol);
    } 
    else if(symbol == '+' || symbol == '-' || symbol == '/' || symbol == '*' || symbol == '^')
    { 
      if(operatorStack.head != NULL) 
      {
         //while there is an operator o2 other than the left parenthesis at the top of the operator stack, and (o2 has greater precedence than o1), pop from operator stack to output
        while(precedence(operatorStack.head->data) >= precedence(symbol))
          {
            if(peek(operatorStack.head) != '(')
            {
              char o = pop(operatorStack.head);
              enqueue(output.head, output.tail, o);
            }
            if(operatorStack.head == NULL)
            {
              break;
            }
          }
      }
      push(operatorStack.head, symbol);
    }
    else if(symbol == '(')
    {
      push(operatorStack.head, symbol);
    }
    else if(symbol == ')')
    {
      //while operator at top of operator stack is not left parantheses, pop from operator stack to output
      while(peek(operatorStack.head) != '(')
        {
          char o = pop(operatorStack.head);
          enqueue(output.head, output.tail, o);
        }
      pop(operatorStack.head);
    }
    symbol = dequeue(math.head);
  }
  //pops all operators from operator stack to output
  while(peek(operatorStack.head) != '\0')
    {
      char o = pop(operatorStack.head);
      enqueue(output.head, output.tail, o);
    }
  return output;
}

//returns an integer representing precedence of operator
int precedence(char num)
{
  if(num == '\0')
  {
    return 0;
  }
  else if(num == '^')
  {
    return 3;
  } 
  else if(num == '*')
  {
    return 2;
  }
  else if(num == '/')
  {
    return 2;
  }
  else if(num == '+')
  {
    return 1;
  }
  else if(num == '-')
  {
    return 1;
  }
  return 0; //returns 0 if none of these so it will not enter while loop on line 321
}