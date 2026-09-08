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
    int xdepth, ydepth, xparent, yparent;
    void dfs(TreeNode*root,int dep, int par_val,int x,int y){
        if(root == NULL) return;
        if(root->val == x){
            xdepth = dep;
            xparent = par_val;
            return;
        }

        if(root->val == y){
            ydepth = dep;
            yparent = par_val;
            return;
        }

        dfs(root->left,dep+1,root->val,x,y);
        dfs(root->right,dep+1,root->val,x,y);
        
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(root->val == x || root->val == y) return false;
        dfs(root,0,0,x,y);

        if(xdepth == ydepth && xparent != yparent) return true;
        return false;
    }
};