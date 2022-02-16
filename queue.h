class queue
{
  public:
    void enqueue(lnode* &head, lnode* &tail, char data);
    char dequeue(lnode* &head);
    queue();

  private:
    lnode* head; //where nodes are dequeued
    lnode* tail; //where nodes are enqueued
  
};

queue::queue()
{
  head = NULL;
  tail = NULL;
}

//adds to queue
void queue::enqueue(lnode* &head, lnode* &tail, char data)
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
char queue::dequeue(lnode* &head)
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
