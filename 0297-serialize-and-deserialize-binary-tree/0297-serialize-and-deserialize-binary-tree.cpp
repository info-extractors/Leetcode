/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "null";

        string root_serialization = to_string(root -> val);
        string left = serialize(root -> left);
        string right = serialize(root -> right);

        return root_serialization + "," + left + "," + right;
    }

    vector<TreeNode*> tokenize(string &s){
        vector<TreeNode*> tokens;

        int left = 0;
        while(left < s.size()){

            if (s[left] == ','){
                left++;
            }else{

                string token = "";
                int right = left;
                while(right < s.size() && s[right] != ','){
                    token += s[right];
                    right++;
                }

                left = right;

                if (token == "null") tokens.push_back(nullptr);
                else tokens.push_back(new TreeNode(stoi(token)));
            }
        }

        return tokens;
    }

    TreeNode* generateTree(vector<TreeNode*> &tokens,int &index){

        if (index >= tokens.size()) return nullptr;

        if (tokens[index] == nullptr){
            index++;
            return nullptr;
        }

        TreeNode* root = tokens[index];
        index++;
        root -> left = generateTree(tokens,index);
        root -> right = generateTree(tokens,index);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<TreeNode*> tokens = tokenize(data);
        int index = 0;
        return generateTree(tokens,index);
    }
};

/*

Whenever the queue cannot filled in the left 
*/ 

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));