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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        if (!l1) return l2;
        if (!l2) return l1;

        ListNode* newNode = new ListNode(0);

        if (l1->val <= l2->val) {
            newNode->val = l1->val;
            newNode->next = mergeTwoLists(l1->next, l2);
        }
        else {
            newNode->val = l2->val;
            newNode->next = mergeTwoLists(l1, l2->next);
        }

        //(l1과 l2사이에 선택되어)만들어진 자신을 return. 
        return newNode;
    }
};