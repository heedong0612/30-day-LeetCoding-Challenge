/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Donghee Lee
// 4/8/2020

class Solution {
public:
    
    /* Two passes */
    // counts total size and returns the middle node
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        int size = 0;
        
        ListNode* counter = head;
        while (counter != nullptr) {
            counter = counter->next;
            size++;
        }
        
        counter = head;
        for (int i = 0; i < size /2; i++) {
            counter = counter->next;
        }
        
        return counter;
    }

    
    
    
    

    
    
    
    /* One-ish pass with sub passes*/
    // As it goes through each nodes, checks if the current node is the middle node
    ListNode* middleNode2(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        if (head->next->next == nullptr) return head->next;
        int count = 0;
        ListNode* candidate = head;
        ListNode* seeker = candidate;
        while(true) {
            if (seeker == nullptr || seeker->next == nullptr) {
                return candidate;
            }
            count++;
            candidate = candidate->next;
            seeker = candidate;
            
            for (int i = 0; i < count; i++) {
                seeker = seeker->next;
            }
        }
        
    }
};