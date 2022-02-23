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
    void helper(ListNode *&p1, ListNode *p2, bool &ans){
        if(!p1 || !p2 || !ans)
            return;
        helper(p1, p2->next, ans);
        int a = p1->val, b = p2->val;
        if(a != b){
            ans = false;
            return;
        }
        p1 = p1->next;
    }
    bool isPalindrome(ListNode* head) {
        bool ans = true;
        helper(head, head, ans);
        return ans;
    }
};