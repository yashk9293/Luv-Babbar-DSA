// Question Link :- https://leetcode.com/problems/search-in-a-binary-search-tree/description/
// Search in a Binary Search Tree

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL) {
            return NULL;
        }
        if(root->val == val) {
            return root;
        }
        else if(root->val > val) {
            return searchBST(root->left, val);
        }
        else {
            return searchBST(root->right, val);
        }
    }
};