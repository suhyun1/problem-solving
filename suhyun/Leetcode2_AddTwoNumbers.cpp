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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    
        ListNode * head = add(l1, l2, 0);
        return head;
    }
    ListNode* add(ListNode* l1, ListNode* l2, int carry) {
        if(!l1 && !l2 && carry == 0) return NULL;
        
        int val1 = l1 ? l1 -> val : 0;
        int val2 = l2 ? l2 -> val : 0;

        ListNode* head = new ListNode((val1 + val2 + carry) % 10);
        head -> next = add( l1? l1 -> next : NULL, l2? l2 -> next : NULL, val1 + val2 + carry >= 10 ? 1: 0);
        return head;
    }
};