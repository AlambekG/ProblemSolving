/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sm = 0;
    void dfs(TreeNode* v, string s){
         s += char(v->val + 48);
         if(v->left) dfs(v->left,  s);
         if(v->right) dfs(v->right, s);
        
         if(!v->left && !v->right) { printf("%s\n", s.c_str());
             sm += stoi(s, nullptr, 2);}
    }
    int sumRootToLeaf(TreeNode* root) {
         dfs(root, "");
         return sm;
    }
};