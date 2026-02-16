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

    TreeNode* inorderSuccessor(TreeNode* root){
        while(root -> left){
            root = root -> left;
        }

        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if (root == nullptr){
            return nullptr;
        }
        
        if (root -> val < key){
            cout << root -> val << endl;
            root -> right = deleteNode(root -> right,key);
        }
        else if (root -> val > key){
            cout << root -> val << endl;
            root -> left = deleteNode(root -> left,key);
        }else if (root -> val == key){

            if (!root -> left && !root -> right) return nullptr;
            else if (!root -> left && root -> right){
                TreeNode* temp = root -> right;
                delete root;
                return temp;
            }else if (root -> left && !root -> right){
                 TreeNode* temp = root -> left;
                delete root;
                return temp;
            }else{
                TreeNode* inSucc = inorderSuccessor(root -> right);
                root -> val  = inSucc -> val;
                root -> right = deleteNode(root -> right,inSucc -> val);
            }
        }

        return root;
    }
};