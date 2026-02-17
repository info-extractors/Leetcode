/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;

        if (root -> val == p -> val || root -> val == q -> val) return root;

        TreeNode* left = nullptr;
        TreeNode* right = nullptr;

        if (p -> val > root -> val){
            right = lowestCommonAncestor(root -> right,p,q);
        }
        else if (p -> val < root -> val){
            left = lowestCommonAncestor(root -> left,p,q);
        }

        if (q -> val > root -> val){
            right = lowestCommonAncestor(root -> right,p,q);
        }
        else if (q -> val < root -> val){
            left = lowestCommonAncestor(root -> left,p,q);
        }

        if (left && right) return root;
        else if (left && !right) return left;
        else if (!left && right) return right;

        return nullptr;
    }
};