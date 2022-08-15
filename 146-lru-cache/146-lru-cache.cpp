class LRUCache {
    
    class Node{
        public:
        
         int key;
         int val;
         Node* prev;
         Node* next;
        
         Node(int key , int val)
         {
             this->key = key;
             this->val = val;
         }
    };
    
     map<int, Node* > mp;
     Node* head;
     Node* tail;
     int cap;
    
     void insertNode(Node* newnode)
     {
        // Node* temp = head->next;
        newnode->next = head->next;
        newnode->prev = head;
        head->next = newnode;
        newnode->next->prev = newnode;
     }
    
     void deleteNode(Node* delnode)
     {
         // Node* delprev = delnode->prev;
         delnode->prev->next = delnode->next;
         delnode->next->prev = delnode->prev;
         // delnext->prev = delprev;
         
         delete delnode ;
     }
    
public:
    LRUCache(int capacity) {
        cap = capacity ;
        head = new Node(-1 , -1);
        tail = new Node(-1 , -1);
        head->next = tail ;
        tail->prev = head ;
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;
        
        Node* temp = mp[key];
        mp.erase(key);
        
        Node* newnode = new Node(key , temp->val) ;
        deleteNode(temp);
        insertNode(newnode);
        
        mp[key] = newnode ;
        
        return newnode->val;
    }
    
    void put(int key, int value) {
        
        if(mp.count(key))
        {
            deleteNode(mp[key]);
            mp.erase(key);
        }
        
        if(mp.size() == cap)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
        Node* temp = new Node( key , value) ;
        
        mp[key] = temp;
        
        insertNode(temp) ;
        
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */