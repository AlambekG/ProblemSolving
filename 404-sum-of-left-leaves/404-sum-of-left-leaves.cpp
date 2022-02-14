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
    int sumOfLeftLeaves(TreeNode* root) {
          int sm = 0;
          if(root->left && !root->left->left && !root->left->right)
               sm += root->left->val;
          if(root->left){
              sm += sumOfLeftLeaves(root->left);
          }
          if(root->right)
              sm += sumOfLeftLeaves(root->right);
          return sm;
    }
};