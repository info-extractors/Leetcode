/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* reverseList(ListNode* head){

        if (head == nullptr || head -> next == nullptr){
            return head;
        }

        ListNode* newHead = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = nullptr;

        return newHead;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode* prev = nullptr;
        ListNode* right_node = nullptr;

        ListNode* curr = head;
        int pos = 1;

        while(curr){
            
            if (pos == left - 1){
                prev = curr;
            }
            
            if (pos == right){
                right_node = curr;
            }

            pos++;
            curr = curr -> next;
        }

        //Now disconnect the nodes 
        ListNode* middlePart = nullptr;
        if (prev){
            middlePart = prev -> next;
        }else{
            middlePart = head;
        }

        ListNode* rightPart = right_node -> next;
        right_node -> next = nullptr;

        ListNode* reversedHead = reverseList(middlePart);

        if (prev){
            prev -> next = right_node;
        }else{
            head = reversedHead;
        }

        middlePart -> next = rightPart;

        return head;
    }
};