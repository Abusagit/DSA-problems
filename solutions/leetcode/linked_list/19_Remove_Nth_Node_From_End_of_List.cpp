struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};




class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast_p = head->next;
        ListNode* slow_p = head;
        ListNode* prev = nullptr;

        int fast_position = 2;
        int slow_position = 1;

        while (fast_p != nullptr && fast_p->next != nullptr){
            fast_position+=2;
            slow_position++;

            fast_p = fast_p->next->next;
            
            prev = slow_p;
            slow_p = slow_p->next;

        }
        // fast_p->next == nullptr
        // need to check fast_p

        if (fast_p == nullptr){
            fast_position--;
        }


        // cout << fast_position;

        int node_to_delete_position = fast_position - n + 1;

        if (slow_position < node_to_delete_position){
            while (slow_position < node_to_delete_position){
                prev = slow_p;
                slow_p = slow_p->next;
                slow_position++;
            }

        } else if (slow_position > node_to_delete_position){
            slow_position = 1;
            slow_p = head;
            prev = nullptr;
            while (slow_position < node_to_delete_position){
                prev = slow_p;
                slow_p = slow_p->next;
                slow_position++;
            }

        }
        //slow_p is exactly on the node_to_delete_position

        //slow_p is exactly on the node_to_delete position

        if (slow_p->next == nullptr && prev == nullptr){
            // delete element from single-linked list
            return nullptr;
        }
 
        if (slow_p->next == nullptr) { 
            // need to delete last element
            prev->next = nullptr;
        } else if (prev == nullptr){
            //need to delete 1st element
            head = head->next;
        } else {
            //delete element inside the list
            prev->next = slow_p->next;
        }

        return head;


    }
};