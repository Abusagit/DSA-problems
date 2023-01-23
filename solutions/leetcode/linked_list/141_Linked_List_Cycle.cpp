# include <stdio.h>
# include <unordered_set>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    
    };



class Solution {
public:
    bool hasCycle(ListNode *head) {
        std::unordered_set<ListNode*> visited_nodes;

        while (head != nullptr){
            if (visited_nodes.find(head) != visited_nodes.end()){
                return true;    
            }

            visited_nodes.insert(head);
            head = head->next;

        }

        return false;
    }

    bool hasCycle_no_memory(ListNode *head){

        //on a signle iteration the distance between fast and slow pointer is reduced by 1 ==> time for fast pointer to reach the slow pointer is O(n)

        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != nullptr && fast->next != nullptr){

            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow){ // check if they intersect
                return true;
            }

        }

        return false;
    }
};

