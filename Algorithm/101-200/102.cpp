/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 //bfs
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr)
        {
            return res;
        }
        queue<TreeNode*> q;
        q.emplace(root);
        while(!q.empty())
        {
            int n = q.size();
            vector<int> vec;
            for(int i=0;i<n;++i)
            {
                TreeNode * temp = q.front();
                q.pop();
                vec.emplace_back(temp->val);
                if(temp->left)q.emplace(temp->left);
                if(temp->right)q.emplace(temp->right);
            }
            res.emplace_back(vec);
        }
        return res;
    }
};
