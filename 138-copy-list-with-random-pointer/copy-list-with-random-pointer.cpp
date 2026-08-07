/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    void insertCopy(Node* head) {
        Node* temp = head;

        while(temp != NULL) {
            Node* nextEle = temp->next;
            Node* copyNode = new Node(temp->val);

            copyNode->next = nextEle;
            temp->next = copyNode;
            temp = nextEle;
        }
    }

    void connectRandom(Node* head) {
        Node* temp = head;

        while(temp != NULL) {
            Node* copyNode = temp->next;    
        

            if(temp->random)
                copyNode->random = temp->random->next; 
            else
                copyNode->random = NULL;   
 
            temp = temp->next->next;
        }
    }

    Node* getCopiedList(Node* head) {
        Node* temp = head;
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;

        while(temp != NULL) {
            res->next = temp->next;
            res = res->next;

            temp->next = temp->next->next;
            temp = temp->next;
        }

        return dummyNode->next;
    }
public:
    Node* copyRandomList(Node* head) {
        insertCopy(head);
        connectRandom(head);
        return getCopiedList(head);
    }
};