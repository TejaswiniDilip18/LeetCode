/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* l_sum = dummy;
        int sum = 0, first = 0, second=  0;

        while(l1 != nullptr || l2 != nullptr || first !=0){
            sum = first;

            if(l1 != nullptr){
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2 != nullptr){
                sum += l2->val;
                l2 = l2->next;
            }

            first = sum / 10;
            second = sum % 10;

            l_sum->next = new ListNode(second);
            l_sum = l_sum->next;
        }

        return dummy->next;
    }
};