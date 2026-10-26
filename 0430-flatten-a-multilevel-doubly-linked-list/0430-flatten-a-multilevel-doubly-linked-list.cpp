/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL) {
            return head;
        }

        Node* curr = head;

        while (curr != NULL) {
            if (curr->child != NULL) {
                Node* next = curr->next;

                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                curr->child = NULL;

                Node* tail = curr->next;

                while (tail->next != NULL) {
                    tail = tail->next;
                }

                if (next != NULL) {
                    tail->next = next;
                    next->prev = tail;
                }
            }

            curr = curr->next;
        }

        return head;
    }
};
