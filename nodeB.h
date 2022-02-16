class nodeB: public lnode
{
  nodeb();
  bnode* data;
  lnode* next;
};

nodeB::nodeB()
{
  l->data = NULL;
  l->next = NULL;
}