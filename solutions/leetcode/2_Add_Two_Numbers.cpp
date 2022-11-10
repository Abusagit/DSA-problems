struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int previous_decimal_value = 0;
        int current_sum = l1->val + l2->val + previous_decimal_value;
        previous_decimal_value = current_sum / 10;
        int current_decimal_value = current_sum % 10;

        ListNode* tail = new ListNode(current_decimal_value);
        ListNode* head = tail;

        l1 = l1->next;
        l2 = l2->next;
        while (l1 != nullptr && l2 != nullptr){

            current_sum = l1->val + l2->val + previous_decimal_value;
            previous_decimal_value = current_sum / 10;

            current_decimal_value = current_sum % 10;

            ListNode* new_node = new ListNode(current_decimal_value);

            tail->next = new_node;
            tail = new_node;

            l1 = l1->next;
            l2 = l2->next;
        }

        traverse_remained_list(tail, l1, previous_decimal_value);
        traverse_remained_list(tail, l2, previous_decimal_value);
        
        if (previous_decimal_value != 0){
            ListNode* new_node = new ListNode(previous_decimal_value);
            tail->next = new_node;
        }

        return head;

    }

private:
    void traverse_remained_list(ListNode*& result_tail, ListNode* head, int& previous_decimal_value){

        while (head != nullptr)
        {
            int current_sum = head->val + previous_decimal_value;
            previous_decimal_value = current_sum / 10;

            int current_decimal_value = current_sum % 10;

            ListNode* new_node = new ListNode(current_decimal_value);

            result_tail->next = new_node;
            result_tail = new_node;

            head = head->next;
        }

    }
};