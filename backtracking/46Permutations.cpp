class Solution {
private:
   vector<vector<int>> ret;
   vector<int>temp;
public:
   void setDigui(vector<int>nums,vector<int>temp){//此处直接用void就行了，因为我不需要它递归返回数据
       if(nums.size()==0){
           ret.push_back(temp);
           return;
       }
       for(size_t i=0;i<nums.size();i++){//层次遍历的执行过程如下：先把最左面的子树递归完，然后再依次递归
       //右面的子树绝对不是一起递归完成的
           vector<int>t = temp;
           vector<int>n = nums;
           t.push_back(nums[i]);
           n.erase(n.begin()+i);
           setDigui(n,t);
       }
       }
    vector<vector<int>> permute(vector<int>& nums) {
        setDigui(nums,temp);
        return ret;
    }
};
