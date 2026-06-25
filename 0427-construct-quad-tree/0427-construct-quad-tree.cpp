/*
// Definition for a QuadTree node->
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:

    
    Node* help(vector<vector<int>> &grid,int top,int bottom,int left,int right){

        if (top > bottom || left > right) return nullptr;
        if (top == bottom && left == right){
            return new Node(grid[top][right],true);
        }

        int rowMid = (top + bottom) / 2;
        int colMid = (left + right) / 2;

        Node* tl = help(grid,top,rowMid,left,colMid);
        Node* tr = help(grid,top,rowMid,colMid + 1,right);
        Node* bl = help(grid,rowMid + 1,bottom,left,colMid);
        Node* br = help(grid,rowMid + 1,bottom,colMid + 1,right);

        bool potentialLeaf = tl -> isLeaf && tr -> isLeaf && bl -> isLeaf && br->isLeaf;
        bool validationPassed = (potentialLeaf) ? (tl->val == tr->val && tl->val == bl->val && tl->val == br->val) : false;

        if (validationPassed){
            return new Node(tl->val,true);
        }

        return new Node(0,false,tl,tr,bl,br);
    }

    Node* construct(vector<vector<int>>& grid) {

        return help(grid,0,grid.size() - 1,0,grid[0].size() - 1);
    }
};
