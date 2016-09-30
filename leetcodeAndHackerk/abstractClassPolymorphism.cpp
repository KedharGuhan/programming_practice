class LRUCache :public Cache{
   public : 
    int cp;
    Node *tail, *head;
    LRUCache(int capacity) : cp(capacity), tail(NULL), head(NULL) {}
    void set(int key, int value){
        Node* newNode = nullptr;
        Node *node1, *node2;
        map<int , Node*>::iterator it;
        it = mp.find(key);
        if(it != mp.end())
        {   newNode = (*it).second;
            newNode->value = value;
        }
        /*node1 = newNode->prev;
            node2 = newNode->next;
            if ( node1 == nullptr && node2 == nullptr ){
                // when new node is the only element in the list
                mp[key]= newNode;
            }
            else if ( node2 == nullptr ){
                //when tail is null
                    
                    node1->next = nullptr;
                    tail = node1;
                    newNode->next = head;
                    head = newNode;
                    mp[key]= newNode;
            }
            else {
                //gneric case
                node1->next = node2;
                node2->prev = node1;
                newNode->next = head;
                head = newNode;
                mp[key]= newNode;
            }
        }*/
        else {
            //create new Node 
            newNode = new Node(key, value);
            if( head ){
                newNode->next = head;
                head = newNode;
            }
            else {
                head = newNode;
                tail = newNode;
            }
            mp[key]= newNode;
            if( mp.size() > cp ){
               Node* lastNode = tail->prev;
                mp.erase(tail->key);
                delete(tail);
                tail = lastNode;
                lastNode->next = nullptr;
                
            }
        }
    }
    int get( int key ){
     map<int , Node*>::iterator it;
     it = mp.find(key);   
     if(it == mp.end())
         return -1;
     // move the recently used to front of the queue
     Node* node = (*it).second;
        Node* node1 = node->prev;
        Node* node2 = node->next;
       
        if (node1 && node2 ) {
                //gneric case
                node1->next = node2;
                node2->prev = node1;
                node->next = head;
                head = node;
        }    
        return (*it).second->value;
        
    }
};
