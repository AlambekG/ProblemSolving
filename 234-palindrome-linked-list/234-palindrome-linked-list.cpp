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
    
    ListNode *g_ptr;

bool DFS(ListNode* node)
{
	if (!node)
		return true;
	bool result = DFS(node->next) && node->val == g_ptr->val;
	g_ptr = g_ptr->next;
	return result;
}
    bool isPalindrome(ListNode* head) {
      	g_ptr = head;
	return DFS(head);
    }
};