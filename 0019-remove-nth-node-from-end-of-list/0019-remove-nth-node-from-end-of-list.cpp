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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
           vector<ListNode*>nodes;
           ListNode* tmp = head;
        
           while(tmp){
               nodes.push_back(tmp);
               tmp = tmp -> next;
           }

           if(nodes.size() == 1)
              return nullptr;

           int del = nodes.size() - n;
           if(del == 0) 
                return nodes[del+1];
           
           nodes[del - 1] -> next = nodes[del] -> next;
           return nodes[0]; 
    }
};