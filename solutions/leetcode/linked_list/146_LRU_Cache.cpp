#include <unordered_map>


class Node {
public:
    int val;
    int key;
    Node *next;
    Node *previous;
    Node(int x, int y) : val(x), key(y), next(nullptr), previous(nullptr) {}
 };


class LRUCache {
public:
    LRUCache(int capacity) {
        max_capacity = capacity;

        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->previous = head;

    }
    
    int get(int key) {
        if (key2node_dict.find(key) != key2node_dict.end()){
            delete_node(key2node_dict[key]);
            insert_node(key2node_dict[key]);

            return key2node_dict[key]->val;

        }

        return -1;
    }
    
    void put(int key, int value) {
        if (key2node_dict.find(key) != key2node_dict.end()){
            delete_node(key2node_dict[key]);
        }
        
        key2node_dict[key] = new Node(value, key);
        insert_node(key2node_dict[key]);

        if (key2node_dict.size() > max_capacity){
            key2node_dict.erase(tail->previous->key);
            delete_node(tail->previous);
        }
        
    }

private:
    int max_capacity;
    Node* head;
    Node* tail;

    std::unordered_map<int, Node*> key2node_dict;

    void insert_node(Node* node){
        // insert node as new head
        Node* first_node = head->next;
        head->next = node;
 
        node->previous = head;
        first_node->previous = node;
        node->next = first_node;

    }

    void delete_node(Node* node){
        Node* prev = node->previous;
        Node* next = node->next;

        prev->next = next;
        next->previous = prev;

    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */