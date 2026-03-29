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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        queue<tuple<TreeNode*, int, int>> q;
        q.push({root, 0, 0});
        while(!q.empty()){
            auto[node, hd, vd] = q.front();
            mp[hd][vd].insert(node->val);
            q.pop();
            if(node->left) q.push({node->left, hd-1, vd+1});
            if(node->right) q.push({node->right, hd+1, vd+1});
        }
        vector<vector<int>> ans;
        for(auto &[hd, levelmap]: mp){
            vector<int> col;
            for(auto &[vd, nodes]: levelmap){
                col.insert(col.end(), nodes.begin(), nodes.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};