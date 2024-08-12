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
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;

        ListNode* slow = head;
        ListNode* fast = head;
        
        // Find middle element of the list
        while(fast->next && fast->next->next){
            slow = slow->next; // points to middle element at the end of loop
            fast = fast->next->next;
        }

        // reverse second half of the list
        ListNode* current = slow -> next;
        slow -> next = nullptr;
        ListNode* prev = nullptr; 

        while(current){
            ListNode* next_ptr = current -> next;
            current->next = prev;
            prev = current;
            current = next_ptr;
        }  

        ListNode* first = head; // first list
        ListNode* second = prev; // second list

        // merge both the lists alternatively
        while(second){
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};