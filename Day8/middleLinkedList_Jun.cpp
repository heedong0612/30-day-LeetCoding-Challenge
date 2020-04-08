
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* current = head;
        ListNode* current2 = head;
        while(current2 != NULL) {
            current2 = current2->next;
            if(current2 != NULL) {
                current2 = current2->next;
                current = current->next;
            }
            else {
                break;
            }
        }
        return current;
    }
};