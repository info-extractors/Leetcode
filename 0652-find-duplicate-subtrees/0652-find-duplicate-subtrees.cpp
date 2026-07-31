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

    string hashTree(TreeNode* root,unordered_map<string,pair<TreeNode*,int>> &hashCount){

        if (root == nullptr){
            return "#";
        }

        string leftHash = hashTree(root -> left,hashCount);
        string rightHash = hashTree(root -> right,hashCount);
        string currHash = to_string(root -> val) + ',' + leftHash + ',' + rightHash;

        if (!hashCount.count(currHash)){
            hashCount[currHash] = make_pair(root,1);
        }else{
            hashCount[currHash].second += 1;
        }

        return currHash;
    }

    

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        vector<TreeNode*> duplicateSubTree;
        unordered_map<string,pair<TreeNode*,int>> hashCount;
        hashTree(root,hashCount);


        for(auto it : hashCount){

            cout << it.first << endl;
            if (it.second.second > 1){
                duplicateSubTree.push_back(it.second.first);
            }
        }

        return duplicateSubTree;
    }
};