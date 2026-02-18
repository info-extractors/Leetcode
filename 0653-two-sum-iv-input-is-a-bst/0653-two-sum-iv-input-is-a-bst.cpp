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

    TreeNode* globalRoot;

    bool search(TreeNode* root,int val){
        if (root == nullptr) return false;

        if (root -> val == val) return true;
        if (root -> val < val){
            return search(root -> right,val);
        }

        return search(root -> left,val);
    }


    bool find(TreeNode* root,int k){

        if (root == nullptr) return false;

        if ((k != ((root -> val) * 2)) && search(globalRoot,k - root -> val)) return true;
        return (find(root -> left,k) || find(root -> right,k));
    }

    bool findTarget(TreeNode* root, int k) {
        
        globalRoot = root;
        return find(root,k);
    }
};