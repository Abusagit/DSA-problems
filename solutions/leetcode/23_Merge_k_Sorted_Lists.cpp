#include <vector>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if (lists.size() == 0){
            return nullptr;
        }
        

        if (lists.size() == 1){
            return lists[0];
        }

        std::vector<ListNode*> merged_lists;

        for (int i=0; i + 1< lists.size(); i+=2){
            merged_lists.push_back(merge_2_linked_lists(lists[i], lists[i+1]));
        }

        if (lists.size() % 2 == 1){
            merged_lists.push_back(*(lists.end()-1));
        }

        return mergeKLists(merged_lists);

    }
private:
    ListNode* merge_2_linked_lists(ListNode* head_1, ListNode* head_2){

        if (head_1 == NULL && head_2 == NULL){
            return nullptr;
        }
        if (head_1 == NULL){
            return head_2;
        }

        if (head_2 == NULL){
            return head_1;
        }

        ListNode* head;
        if (head_1->val <= head_2->val){
            head = new ListNode(head_1->val);
            head_1 = head_1->next;
        } else {
            head = new ListNode(head_2->val);
            head_2 = head_2->next;
        }

        ListNode* tail = head;
        while (head_1 != nullptr && head_2 != nullptr){
            if (head_1->val <= head_2->val){
                tail->next = head_1;
                head_1 = head_1->next;
            } else {
                tail->next = head_2;
                head_2 = head_2->next;
            }

            tail = tail->next;
        }

        while (head_1 != nullptr){
            tail->next = head_1;
            head_1 = head_1->next;
            tail = tail->next;
        }

        while (head_2 != nullptr){
            tail->next = head_2;
            head_2 = head_2->next;
            tail = tail->next;
        }

        return head;

    }
};