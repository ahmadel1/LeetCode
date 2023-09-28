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
    int deepestLeavesSum(TreeNode* root) {
        vector<vector<int>>levels;
        vector<int>level;
        TreeNode* curr;
        queue<TreeNode*>q;
        q.push(root);
        q.push(nullptr);
        
        while(!q.empty()){
            curr = q.front();
            q.pop();
            if(curr != nullptr){
                level.push_back(curr -> val);
                if(curr -> left) q.push(curr -> left);
                if(curr -> right) q.push(curr -> right);
            }else{
                levels.push_back(level);
                level.clear();
                if(!q.empty()) q.push(nullptr);
            }
        }

        int res = 0;
        int sz = levels.back().size();
        for(int i = 0; sz>i; i++){
            res += levels.back()[i];
        }
        return res;
    }
};