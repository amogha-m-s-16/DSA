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
    ListNode* countKthNode(ListNode* temp, int k) {
        k -= 1;
        while(temp != NULL && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseLL(ListNode* temp) {
        if(temp == NULL || temp->next == NULL) return temp;

        ListNode* newHead = reverseLL(temp->next);
        ListNode* front = temp->next;
        front->next = temp;
        temp->next = NULL;

        return newHead;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;

        while(temp != NULL) {
            ListNode* kthNode = countKthNode(temp, k);

            if(kthNode == NULL) {
                if(prevNode) prevNode->next = temp;
                break;
            }

            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;
            reverseLL(temp);

            if(temp == head) head = kthNode;
            else prevNode->next = kthNode;

            prevNode = temp;
            temp = nextNode;
        }

        return head;
    }
};