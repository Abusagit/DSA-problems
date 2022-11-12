struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* beginning = new ListNode(0, head);

        ListNode* current_node = head;
        ListNode* previous_node = beginning;

        ListNode* next_node;

        int nodes_in_chain = 1;

        while (current_node->next != nullptr){
            if (nodes_in_chain == k){
                next_node = current_node->next;

                current_node->next = nullptr;
                ListNode* prev_head_of_sublist = previous_node->next;
                ListNode* new_head_of_reversed_sublist = reverse_sublist(prev_head_of_sublist);

                previous_node->next = new_head_of_reversed_sublist;
                prev_head_of_sublist->next = next_node;

                previous_node = prev_head_of_sublist;
                
                current_node = previous_node;
                nodes_in_chain = 0;

            }
            
            current_node = current_node->next;
            nodes_in_chain++;
        }

        if (nodes_in_chain == k){
            next_node = current_node->next;

            current_node->next = nullptr;
            ListNode* prev_head_of_sublist = previous_node->next;
            ListNode* new_head_of_reversed_sublist = reverse_sublist(prev_head_of_sublist);
            
            previous_node->next = new_head_of_reversed_sublist;
            prev_head_of_sublist->next = next_node;
            
        }
        return beginning->next;
    }
private:

    ListNode* reverse_sublist(ListNode* subhead){

        ListNode* new_head = nullptr;

        while (subhead != nullptr){
            ListNode* next = subhead->next;

            subhead->next = new_head;
            new_head = subhead;

            subhead = next;
        }

        return new_head;
    }
};