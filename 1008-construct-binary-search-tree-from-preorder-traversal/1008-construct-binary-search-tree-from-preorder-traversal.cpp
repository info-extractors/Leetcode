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

    TreeNode* construct(vector<int> &preorder,int &index,long long min,long long max){

      if (index >= preorder.size() || (preorder[index] < min || preorder[index] > max)) return nullptr;
      int value = preorder[index];
      TreeNode* root = new TreeNode(value);
      index = index + 1;

      root -> left = construct(preorder,index,min,value);
      root -> right = construct(preorder,index,value,max);

      return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int index = 0;
        TreeNode* root = construct(preorder,index,LLONG_MIN,LLONG_MAX);
        return root;
    }
};