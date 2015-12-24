/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
深度遍历的方法
class Solution {//可以用DFS即回溯加上递归来做,左右根后序可以试试
   public://每个子树返回的是此之树系统所最小的深度，每道题的深度遍历都要有一定的改进；考虑了几种返回的情况，包括考虑节点为空；
  // 考虑节点为叶节点,考虑节点只有左子树或者节点只有右之树
  //递归函数就是把该做的递归情况写好，把推出条件写好；然后最重要的是在递归的过程中要想方设法把题目中需要
  //做的任务完成
   int minDepth(TreeNode *root) {
       //考虑的节点为空
       if(root==NULL) return 0;
       int lmin = minDepth(root->left);
       int rmin = minDepth(root->right);
       //考虑的节点度为0
       if(lmin==0 && rmin==0)
       return 1;
       //考虑的节点只有一个子树存在度为1
       if(lmin==0)
       return rmin+1;
       else if(rmin==0)
       return lmin+1;
       //考虑的节点有两个子树存在度为2
       return min(lmin,rmin)+1;
    }
};
