class Solution {//整体考虑完再考虑边界情况
private://旧的数据集和新的数据集每一步里面都要进行操作
   vector<vector<int>> ret;
    vector<int> temp;    
public://穷举递归中的一种，还有一种是穷举所有的排列
     void setDigui(int n,int &numSize,vector<int> nums,vector<int> temp){//temp和nums都是赋值关系
         if(n==numSize){//此处不加应用是因为我需要很多不同的temp来存储不同的结果
             sort(temp.begin(),temp.end());
             ret.push_back(temp);
             return;
         }
          int t = nums[0];
          nums.erase(nums.begin());
         setDigui(n+1,numSize,nums,temp);//总之我就按递归执行的顺序是一句话之后再一句话就行了，具体想想不通了
         temp.push_back(t);
         setDigui(n+1,numSize,nums,temp);
         }
vector<vector<int>> subsets(vector<int>& nums) {
        int numSize = nums.size();
        setDigui(0,numSize,nums,temp);
        return ret;
        }
};
