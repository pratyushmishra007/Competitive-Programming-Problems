struct Node{
    int key, data;
    Node *prev, *next;
    Node(int k, int v) :  key(k), data(v), prev(NULL), next(NULL) {}
};
class LRUCache {
private:
    map<int, Node*> mp;
    Node *head, *tail;
    int capacity;
    void add_node(Node *a){
        a->next = head->next;
        a->prev = head->next->prev;
        head->next = a;
        a->next->prev = a;
    }
    void delete_node(Node *a){
        a->prev->next = a->next;
        a->next->prev = a->prev;
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        else {
            delete_node(mp[key]);
            add_node(mp[key]);
            return mp[key]->data;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            mp[key]->data = value;
            delete_node(mp[key]);
            add_node(mp[key]);
        }
        else {
            if(mp.size() == capacity){
                Node *node = tail->prev;
                delete_node(node);
                mp.erase(node->key);
                delete node;
            }
            Node *node = new Node(key, value);
            add_node(node);
            mp[key] = node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */