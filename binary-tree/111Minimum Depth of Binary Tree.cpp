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
   private://层次遍历需要使用队列加循环即可，不需要使用递归的思想，通过层次遍历找到第一个
   //叶子节点就是最小的深度
   int depth=1; 
   public:
   int minDepth(TreeNode *root) {
      if(root==NULL) return 0;
      queue<TreeNode*>q;
      q.push(root);
      while(!q.empty()){
          int size = q.size();//确定下一层二叉树的元素数
          for(int i=0;i<size;i++){//完成二叉树每一层的遍历；
              TreeNode* temp = q.front();
              q.pop();
              if(temp->left==NULL && temp->right==NULL) return depth;
              if(temp->left)
              q.push(temp->left);
              if(temp->right)
              q.push(temp->right);
              }
              depth++;
      }
     }
};
