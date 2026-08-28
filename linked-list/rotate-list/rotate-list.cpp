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
    ListNode* findTailNode(ListNode* tail, int k) {
        int cnt = 1;
        while(tail != NULL) {
            if(cnt == k) return tail;
            cnt++;
            tail = tail->next;
        }

        return tail;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* temp = head;
        int len = 1;

        while(temp->next != NULL) {
            temp = temp->next;
            len += 1;
        }

        if(k % len == 0) return head;

        k = k % len;

        temp->next = head;
        ListNode* getTail = findTailNode(head, len - k);

        head = getTail->next;
        getTail->next = NULL;

        return head;
    }

};