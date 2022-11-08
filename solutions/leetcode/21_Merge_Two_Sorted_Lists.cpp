struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if ((list1 == nullptr) && list2 == nullptr){
            return nullptr;
        }
        if ((list1 != nullptr) && (list2 == nullptr)){
            return list1;
        }
        if ((list1 == nullptr) && (list2 != nullptr)){
            return list2;
        }
        
        
        ListNode* head;

        if (list1->val <= list2->val){
            head = list1;
            list1 = list1->next;
        } else {
            head = list2;
            list2 = list2->next;
        }
        
        head->next = nullptr;
        
        ListNode* tail = head;
        while ((list1 != nullptr) && (list2 != nullptr)){
            if (list1->val <= list2->val){
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            
            tail = tail->next;
            tail->next = nullptr;
        }
        
        while (list1 != nullptr){
            tail->next = list1;
            list1 = list1->next;
            
            tail = tail->next;
            tail->next = nullptr;
        }
        while (list2 != nullptr){
            tail->next = list2;
            list2 = list2->next;
            tail = tail->next;
            tail->next = nullptr;
        }
        
        return head;
        
    }
};