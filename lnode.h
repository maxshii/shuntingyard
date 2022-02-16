//struct for a node of a linear linked list
class lnode
{
  lnode(char data);
  char data;
  lnode* next;
};

//creates new lnode
lnode::lnode(char data)
{
  lnode* l = new lnode();
  l->data = data;
  l->next = NULL;
  return l;
}