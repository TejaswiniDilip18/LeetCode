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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // move fast n step ahead
        for(int i=0; i<=n; i++){
            fast = fast->next;
        }

        // move both slow and fast
        while(fast != nullptr){
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* temp = slow->next; 

        slow-> next = slow->next->next; // link (n-1)st and (n+1)st node

        delete temp; // remove nth node

        ListNode* result = dummy->next;
        delete dummy;

        return result;
    }
};