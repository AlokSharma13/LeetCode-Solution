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
    void dfs(TreeNode* root, int ts,vector<int>&pathsum,vector<vector<int>>&ans){
        if(root == NULL) return;
        pathsum.push_back(root->val);
        if(root->left == NULL && root->right == NULL){
            int sum = accumulate(pathsum.begin(), pathsum.end(),0);
            if(sum == ts)ans.push_back(pathsum);
            pathsum.pop_back();
            return;
        }
        dfs(root->left,ts,pathsum,ans);
        dfs(root->right,ts,pathsum,ans);
        pathsum.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>pathsum;
        vector<vector<int>>ans;
        dfs(root,targetSum,pathsum,ans);
        return ans;
    }
};