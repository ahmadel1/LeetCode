/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*>s;
        while(head){
            int sz = s.size();
            s.insert(head);
            if(sz == s.size())
                return true;
            head = head->next;

        }
        return false;
    }
};