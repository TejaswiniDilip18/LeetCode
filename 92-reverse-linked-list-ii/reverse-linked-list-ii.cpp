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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) {
            return head;
        }
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;

        for (int i = 1; i < left; ++i){
            prev = prev->next;
        }    

        ListNode* curr = prev->next;
        ListNode* tail = curr;
        ListNode* before_sublist = prev;

        for (int i = 0; i < right - left + 1; ++i){
            ListNode* next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }

        before_sublist->next = prev; // `prev` is now the first node of the reversed sublist
        tail->next = curr;  // `current` is the node right after the `right` position

        return dummy->next;
    }
};