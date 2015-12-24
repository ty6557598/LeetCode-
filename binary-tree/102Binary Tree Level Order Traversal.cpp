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
//使用queue实现层次遍历，然后就是要注重代码的缜密性
  vector<vector<int>> levelOrder(TreeNode* root) {
      vector< vector<int> >ret;
      queue<TreeNode*>Q;
      Q.push(root);//Q队列存放指向TreeNode的指针
      if(root==NULL) return ret;//只有指针这种司马东西可以用NULL，其余都不能用NULL
      while(!Q.empty()){//外层循环为退出的条件
          col.clear();
          int size = Q.size();
          for(int i=0;i<size;i++){//对相同层次的节点进行遍历的循环，通过队列可实现此功能
              TreeNode *temp = Q.front();
              Q.pop();//堆栈不存放某节点后可以通过之前指向的指针继续应用此节点的数据
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
    return ret;
    }
};
