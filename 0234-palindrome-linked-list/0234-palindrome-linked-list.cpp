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


    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;

        while(head){
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;

        ListNode *slow= head;
        ListNode *fast = head;

        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow = reverse(slow);

        while(slow)
        {
            if(head->val != slow->val)
                return false;
            
            head = head->next;
            slow = slow->next;
        }

        return true;
    }
};