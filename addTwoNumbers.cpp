/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* root = new ListNode(-1);
        ListNode* cNode = root;
        while (l1 != NULL || l2 != NULL) {
            int d1 = 0;
            int d2 = 0;
            if (l1 != NULL) {
                d1 = l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                d2 = l2->val;
                l2 = l2->next;
            }
            cNode->next = new ListNode((d1+d2+carry)%10);
            cNode = cNode->next;
            carry = (d1+d2+carry) / 10;
        }
        if (carry == 1) cNode->next = new ListNode(1);
        return root->next;
    }
};
