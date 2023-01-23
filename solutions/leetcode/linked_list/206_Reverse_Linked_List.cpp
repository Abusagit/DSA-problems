struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* tail_node = nullptr;
        
        while (head!= nullptr){
            
            ListNode* next_node = head->next;
            head->next = tail_node;
            tail_node = head;
            head = next_node;
        }
        
        return tail_node;
    }
};