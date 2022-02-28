/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
         if(!root) return 0;
         int h = 0;
         for(auto i : root->children)
              h = max(h, maxDepth(i));
         return h + 1;
    }
};