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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*>st;
        while(headA){
            st.insert(headA);
            headA = headA -> next;
        }
        while(headB){
            int sz = st.size();
            st.insert(headB);
            if(sz == st.size())
                return headB;
            headB = headB -> next;
        }
        return nullptr;
    }
};