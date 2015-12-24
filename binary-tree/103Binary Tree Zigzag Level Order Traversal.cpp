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
private:
    vector<int>col;    
public://第一层左到右，第二层右到左依次类推
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector< vector<int> >ret;
        if(root==NULL) return ret;
        queue<TreeNode*>Q;
        Q.push(root);
        while(!Q.empty()){
            col.clear();
            int size = Q.size();
            for(int i=0;i<size;i++){
                TreeNode *temp = Q.front();
                Q.pop();
                col.push_back(temp->val);
                if(temp->left){
                    Q.push(temp->left);
                }
                if(temp->right){
                    Q.push(temp->right);
                }
                }
            ret.push_back(col);
                }
        for(int j=1;j<ret.size();j=j+2){
            reverse(ret[j].begin(),ret[j].end());
             }
        return ret;
        }
};
