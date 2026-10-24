#include <algorithm>

using namespace std;

// Fast I/O optimization
inline const auto optimize = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Node {
public:
    int lower;
    int upper;
    Node* left;
    Node* right;

    Node(int l, int r) {
        lower = l;
        upper = r;
        left = nullptr;
        right = nullptr;
    }
};

class RangeModule {
private:
    Node* root;

    // Standard BST insertion for a single node
    Node* insert(Node* curr, int l, int r) {
        if (!curr) return new Node(l, r);
        if (r < curr->lower) {
            curr->left = insert(curr->left, l, r);
        } else if (l > curr->upper) {
            curr->right = insert(curr->right, l, r);
        }
        return curr;
    }

    // Helper to remove a node from the BST and return the new subtree root
    Node* removeNode(Node* curr) {
        if (!curr->left) {
            Node* rightChild = curr->right;
            delete curr;
            return rightChild;
        }
        if (!curr->right) {
            Node* leftChild = curr->left;
            delete curr;
            return leftChild;
        }
        Node* rightChild = curr->right;
        Node* leftChild = curr->left;
        delete curr;

        // Attach leftChild to the leftmost node of rightChild
        Node* leftmost = rightChild;
        while (leftmost->left) leftmost = leftmost->left;
        leftmost->left = leftChild;
        return rightChild;
    }

    // Helper to find and remove any overlapping/touching node across the BST
    bool findAndRemoveOverlap(Node*& curr, int& l, int& r) {
        if (!curr) return false;

        // Half-open overlap/touch condition: !(curr->upper < l || curr->lower > r)
        if (!(curr->upper < l || curr->lower > r)) {
            l = min(l, curr->lower);
            r = max(r, curr->upper);
            curr = removeNode(curr);
            return true;
        }

        if (l < curr->lower) {
            if (findAndRemoveOverlap(curr->left, l, r)) return true;
        }
        if (r > curr->upper) {
            if (findAndRemoveOverlap(curr->right, l, r)) return true;
        }

        return false;
    }

    // Helper to find and process overlapping nodes for removeRange
    bool findAndProcessOverlapRemove(Node*& curr, int l, int r, RangeModule* rm) {
        if (!curr) return false;

        // Strict overlap condition for removal: max(curr->lower, l) < min(curr->upper, r)
        if (max(curr->lower, l) < min(curr->upper, r)) {
            int cLower = curr->lower;
            int cUpper = curr->upper;
            curr = removeNode(curr);

            // Re-add any leftover left or right portions
            if (cLower < l) {
                rm->addRangeInternal(cLower, l);
            }
            if (r < cUpper) {
                rm->addRangeInternal(r, cUpper);
            }
            return true;
        }

        if (l < curr->upper) {
            if (findAndProcessOverlapRemove(curr->left, l, r, rm)) return true;
        }
        if (r > curr->lower) {
            if (findAndProcessOverlapRemove(curr->right, l, r, rm)) return true;
        }

        return false;
    }

    void addRangeInternal(int l, int r) {
        // Keep finding and absorbing all overlapping nodes until none are left
        while (findAndRemoveOverlap(root, l, r));
        // Insert the fully merged single range
        root = insert(root, l, r);
    }

    void clearTree(Node* curr) {
        if (!curr) return;
        clearTree(curr->left);
        clearTree(curr->right);
        delete curr;
    }

public:
    RangeModule() {
        root = nullptr;
    }
    
    ~RangeModule() {
        clearTree(root);
    }
    
    void addRange(int left, int right) {
        addRangeInternal(left, right);
    }
    
    bool queryRange(int left, int right) {
        Node* curr = root;
        while (curr != nullptr) {
            if (left >= curr->lower && right <= curr->upper) {
                return true;
            } else if (right <= curr->lower) {
                curr = curr->left;
            } else if (left >= curr->upper) {
                curr = curr->right;
            } else {
                break;
            }
        }
        return false;
    }
    
    void removeRange(int left, int right) {
        while (findAndProcessOverlapRemove(root, left, right, this));
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left, right);
 * bool param_2 = obj->queryRange(left, right);
 * obj->removeRange(left, right);
 */
/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left, right);
 * bool param_2 = obj->queryRange(left, right);
 * obj->removeRange(left, right);
 */

/*

Now here is the idea create a class Node

class Node{
    public:

    int lower;
    int upper;

    Node* left;
    Node* right;


    Node(int l,int r){
        lower = l;
        upper = r;

        left = nullptr;
        right = nullptr;
    }
};

when addRange is done insert the node in binary search tree 

lets say we did addRange(10,20)
in tree we would store the actual range that is 10 , 19
 Now we have this tree 

        (10,19)
        /       \
     nullptr     nullptr


     On left side of the tree we would store all the range whose upper bound is smaller than 10 
     and on right we would store all the ranges whose lower bound is greater than 19

     lets say we call addRange(21,40) 

     so we would create this 

           (10,19)  
           /      \ 
        nullptr    (21,39)

        one more addRange(1,8)

        (10,19)
        /       \
    (1,7)     (21,40)

    Now lets call removeRange(14,16)

    Now ranges has to be divided like this (10,14) and (16,20)

    but we cannot discet this tree so one of the node remains the node and rest is pushed into other the binary search tree

                (16,19)  
               /      \
        (10,13)       (21,40)
        /
    (1,8)
        

    removeRange(8,11)

    it actually means remove 8 - 10

    first we would check if there any internal that is super internval of 8-10 like 14 - 15 was of
    10-19

    (10,13) there is an overlap but not a proper overlap so we do it anyway

    10-13 breaks into (10 - 10) and (11-13)

    as left part of this is remove (10-13) get converted into (11-13)

    and this operation continues into the left branh 

    (1-8) get converted into (1-7)

    so new tree is 

                (16,19)  
               /      \
        (11,13)       (21,40)
        /
    (1,7)

                

*/

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */