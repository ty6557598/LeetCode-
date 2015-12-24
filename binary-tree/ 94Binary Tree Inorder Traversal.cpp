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
public://左跟右的遍历顺序,非递归的方法要注重穷尽到最后的分叉，然后再进行左跟右，此为关键。但是
//整个代码还是有点难想的，需要多思考啊
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ret;
        if(root==NULL)return ret;
        stack<TreeNode*>s;
        TreeNode* temp=root->left;
        s.push(root);
        while(!s.empty()||temp!=NULL){//必须两者都可以进行之后的程序，因为可能堆栈为空但是temp有值的情况下还是不允许推出
            if(temp!=NULL){//完成左子树的穷尽任务
                s.push(temp);
                temp = temp->left;
            }
            else//完成左根右的任务
            {//else有两种情况都符合下面的代码，假设最左子树有右子树，那么等于先读此根节点然后再读右子树的节点；
 //如果最左子树没有右子树那么就读到上一层的根节点然后再读右节点完成左根右的部分，总之代码完美的模拟了中序遍历。
                temp = s.top();
                s.pop();
                ret.push_back(temp->val);
                temp = temp->right;
                }
            
        }
        return ret;
        }
};
