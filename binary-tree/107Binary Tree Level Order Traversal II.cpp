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
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector< vector<int> >ret;
        if(root==NULL) return ret;
        queue<TreeNode*>Q;
        Q.push(root);
        while(!Q.empty()){
            col.clear();
            int size = Q.size();
            for(int i=0;i<size;i++){//把上一层的pop掉，留下下一层的。这样size就是这一层的size这样下面可以用它来控制
                TreeNode *temp = Q.front();
                Q.pop();
                if(temp->left){
                Q.push(temp->left);
                }
                if(temp->right){
                Q.push(temp->right);
                }
                col.push_back(temp->val);
                    }
            ret.push_back(col);
            }
        reverse(ret.begin(),ret.end());
        return ret;
     }
};
