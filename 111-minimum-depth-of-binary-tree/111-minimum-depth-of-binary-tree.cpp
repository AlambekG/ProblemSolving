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
    int minDepth(TreeNode* root) {
        queue <pair <TreeNode*, int> > q;
        
        if(root)
        q.push(make_pair(root, 1));
        while(!q.empty()){
             TreeNode* v = q.front().first;
             int d = q.front().second;
             q.pop();
             if(!v->left && !v->right) return d; 
             if(v->left) q.push(make_pair(v->left, d + 1));
             if(v->right) q.push(make_pair(v->right, d + 1));
        }
        return 0;
    }
};