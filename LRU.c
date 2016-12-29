using namespace std;
// linked list to store the order of elements
//nsert to head and delete the least recently used from head->prev;
class Cache{
    private:
    int size;
    map<key, Node>
    int max_size;
    LRUCache* head, *tail;
    // called when entry is present in the cache and rearrange the linked list
    // to bring the entry to the front
    removeAndAttach(Node* n)
    { // removing the node from existing place
      n->prev->next = n ->next;
      n->next->prev = n->prev

      //attaching to front
      n->next = head->next;
      n->prev = head;
      head-> next = n;
      n->next->prev = n;
    }
    insertFront(Node*n){
      n->next = head->next;
      head->next = n;

    }
    public :
    Cache(int max_size)
    {
      Node* head = new Node();
      Node* tail = new Node();
      tail -> next = head;

    }
}
struct LRUCache{
  struct LRUCache* next;
  struct LRUCache* prev;
  int Key,Value;
}
typedef struct LRUCache Node
//hashmap for find operations

void insert(int key, int value){
  size++;
  Node *n = map.find(key);
  if ( n )
  {
    removeAndAttach(n);

  }
  if (size > max)
  {
    removeTail();
    Node* n = createNode(key, value);
    map.insert(key, n);
  }
  else
  {
    Node* n = createNode(key, value);
    insertFront(n);
    map.insert(key, n);
  }
}
