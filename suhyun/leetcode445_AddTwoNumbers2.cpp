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
        stack<int> s1;
        stack<int> s2;
        
        while (l1 != NULL) {
            s1.push(l1 -> val);
            l1 = l1 -> next;
        }
        while (l2 != NULL) {
            s2.push(l2 -> val);
            l2 = l2 -> next;
        }
        
        ListNode* node = new ListNode(0);
        
        int carry = 0;
        while(!s1.empty() || !s2.empty()) {
            int val1 = 0, val2 = 0;
            if(!s1.empty()) {
                val1 = s1.top();
                s1.pop();
            }
            if(!s2.empty()) {
                val2 = s2.top();
                s2.pop();
            }

            int sum = val1 + val2 + carry;
            carry = sum / 10;
            
            node -> val = sum % 10;
            ListNode* prevNode = new ListNode(0);
            prevNode -> next = node;
            node = prevNode;
            
        }
        if(carry > 0) {
            node -> val = carry;
        }
        
        return node -> val == 0 ? node -> next : node;
    }
  
};