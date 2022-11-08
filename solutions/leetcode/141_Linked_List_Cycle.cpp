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
};