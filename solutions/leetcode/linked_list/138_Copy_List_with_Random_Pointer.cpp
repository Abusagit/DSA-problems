#include <stdio.h>
#include <unordered_map>
#include <unordered_set>

#include <stack>

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        std::unordered_map<Node*, Node*> old_pointer_to_new_pointer;
        std::stack<Node*> old_pointers_stack;

        //forward pass - initialize new nodes

        Node* current_node = head;
        while (current_node != nullptr)
            {
                Node* new_node = new Node(current_node->val);
                old_pointer_to_new_pointer[current_node] = new_node;

                old_pointers_stack.push(current_node);

                current_node = current_node -> next;
            }
        
        //backward pass - assign links to deep-copied nodes



        while (!old_pointers_stack.empty()){

            Node* old_pointer = old_pointers_stack.top();
            old_pointers_stack.pop();

            old_pointer_to_new_pointer[old_pointer]->next = old_pointer_to_new_pointer[old_pointer->next];
            old_pointer_to_new_pointer[old_pointer]->random = old_pointer_to_new_pointer[old_pointer->random]; // points to the deep-copy of a node
        }

        return old_pointer_to_new_pointer[head];
        
    }
};