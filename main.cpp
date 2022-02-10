/*
 * An implementation of the Shunting Yard Algorithm that uses stack, queue, and tree data structures.
 * Author: Max Shi
 * Last modified: 2/10/2022
 */

using namespace::std;

//struct for a node of a linear linked list
struct lnode
{
  char data;
  lnode* next;
  
};

lnode* newLnode(char data);
void push(lnode* &head, char data);
char pop(lnode* &head);
char peek(lnode* head);
void printList(lnode* head); 

int main()
{
  lnode* head = NULL;
  push(head, '2');
  push(head, '4');
  printList(head);
}

//creates new lnode
lnode* newLnode(char data)
{
  lnode* lnode = new lnode();
  lnode->data = data;
  lnode->next = NULL;
  return lnode;
}

//adds to top of stack
void push(lnode* &head, char data)
{
  lnode* lnode = newLnode(data);
  lnode->next = head; //next points to current head
  head = lnode; //head now points to the new node
}

//returns top of stack
char pop(lnode* &head)
{
  if(head == NULL)
    {
      return NULL;
    }

  //move head to next and return data in old head
  char data = head->data;
  node* temp = head;
  head = head->next;
  delete temp;
  return data;
}

 void printList(lnode* head)
 {
   if(head != NULL)
     {
       cout << head->data << " ";
       printList(head->next);
     }
 }