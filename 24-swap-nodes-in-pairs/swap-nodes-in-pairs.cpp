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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* dummyNode = new ListNode(-1);
        ListNode* prevNode = dummyNode;

        ListNode* currentNode = head;

        while(currentNode && currentNode->next) {
            prevNode->next = currentNode->next;
            currentNode->next = prevNode->next->next;
            prevNode->next->next = currentNode;

            prevNode = currentNode;
            currentNode = currentNode->next;
        }

        return dummyNode->next;

    }
};