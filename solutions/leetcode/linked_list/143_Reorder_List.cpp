struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow_pointer = head;
        ListNode* fast_pointer = head;
        ListNode* slow_pointer_prev = nullptr;
        
        // seek for the middle of the list
        while (fast_pointer != nullptr){
            slow_pointer_prev = slow_pointer;
            slow_pointer = slow_pointer->next;
            fast_pointer = fast_pointer->next;
            
            if (fast_pointer == nullptr){
                break;
            } else {
                fast_pointer = fast_pointer->next;
            }
        }
        
        //fast_pointer points to the end of the list, slow_pointer points to (n/2 + 1)th element
        
        //perform reverse of the 2nd halh of the list:
        
        ListNode* middle = slow_pointer;
        
        ListNode* tail_node = nullptr;
        
        while (slow_pointer != nullptr){
            ListNode* next = slow_pointer->next;
            
            slow_pointer->next = tail_node;
            tail_node = slow_pointer;
            
            
            slow_pointer = next;
        }

        ListNode* head_1 = head;
        ListNode* head_2 = tail_node;

        
        // now 2nd half of the array from the end to the middle pointer is reversed;
        
        // split physically the list on 2 halves:
        slow_pointer_prev->next = nullptr;

        while (head_1 != nullptr && head_2 != nullptr){
            ListNode* next_1 = head_1->next;
            ListNode* next_2 = head_2->next;

            head_1->next = head_2;
            head_2->next = next_1;

            head_1 = next_1;
            head_2 = next_2;

        }

        if (head_2 != nullptr){
            head_1->next = head_2;
        }

                
    }
    
};