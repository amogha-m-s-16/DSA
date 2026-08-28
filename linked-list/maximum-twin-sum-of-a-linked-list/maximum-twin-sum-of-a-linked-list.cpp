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
private:
    ListNode* reverseLL(ListNode* slow) {
        if(slow == NULL || slow->next == NULL) return slow;

        ListNode* newHead = reverseLL(slow->next);
        ListNode* front = slow->next;
        front->next = slow;
        slow->next = NULL;

        return newHead;
    }

public:
    int pairSum(ListNode* head) {
        if(head == NULL || head->next == NULL) return head->val;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* reverseHead = reverseLL(slow);
        slow = head;
        
        int ans = 0;
        while(reverseHead) {
            ans = max(ans, (slow->val + reverseHead->val));
            slow = slow->next;
            reverseHead = reverseHead->next;
        }

        return ans;
    }
};