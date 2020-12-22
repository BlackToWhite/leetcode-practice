/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr)
        {
            return res;
        }

        queue<TreeNode*> q;
        q.emplace(root);
        int isOrder = true;

        while(!q.empty())
        {
            int n = q.size();
            deque<int> levelList;
            for(int i=0;i<n;++i)
            {
                TreeNode* temp = q.front();
                q.pop();
                if(isOrder) levelList.emplace_back(temp->val);
                else levelList.emplace_front(temp->val);
                if(temp->left)q.emplace(temp->left);
                if(temp->right)q.emplace(temp->right);
            }
            res.emplace_back(vector<int>{levelList.begin(),levelList.end()});
            isOrder=!isOrder;
        }
        return res;
    }
};
