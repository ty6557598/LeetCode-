/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {//深度遍历的方法再来试试
public://总之深度遍历的思想就是返回当前探索节点所代表的子树系统的最大深度即可，由于这道题比较简单不需要用到伟大的回溯剪纸
    int maxDepth(TreeNode* root) {
       if(root==NULL) return 0;
       int lmax=maxDepth(root->left);
       int rmax=maxDepth(root->right);
       if(lmax==0 && rmax==0) return 1;
       else if(lmax==0) return rmax+1;
       else if(rmax==0) return lmax+1;
       else return max(lmax,rmax)+1;
     }
};
