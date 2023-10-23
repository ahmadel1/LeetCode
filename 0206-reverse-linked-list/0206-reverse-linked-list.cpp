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
    ListNode* LastNode = nullptr;
    void solve(ListNode* prev, ListNode* curr){

        if(curr == nullptr){
            LastNode = prev;
            return;
        }
        solve(curr, curr -> next);
        curr -> next = prev;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        solve(prev, head);
        return LastNode;

    }
};