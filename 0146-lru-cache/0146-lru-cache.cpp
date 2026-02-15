class Node {
public:
    int key, value;
    Node* prev;
    Node* next;

    Node(): key(0), value(0), next(nullptr), prev(nullptr){}
    Node(int k, int v): key(k), value(v), next(nullptr), prev(nullptr){}
};

class LRUCache {
public:
    unordered_map<int, Node*> mp;
    Node* head= nullptr;
    Node* tail = nullptr;
    int capacity=0, size =0;

    void removeNode( Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;

        node->prev = nullptr;  // clean up
        node->next = nullptr;
    }
    
    void insertToTail(Node* node){
        node->prev = tail->prev;
        node->next =tail;
        tail->prev->next = node;
        tail->prev = node;
    }

public:
    LRUCache(int cap) {
        capacity = cap;
        size =0;

        head = new Node();
        tail = new Node();

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key)== mp.end()) return -1;
        Node* node = mp[key];
        removeNode(node);
        insertToTail(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* node = mp[key];
            node->value = value;
            removeNode(node);
            insertToTail(node);
        }
        else{
            Node* node = new Node(key,value);
            mp[key] = node;
            insertToTail(node);
            size++;

            if(size > capacity) {
                Node* lru = head->next;
                removeNode(lru);
                mp.erase(lru->key);
                delete lru;
                size--;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */