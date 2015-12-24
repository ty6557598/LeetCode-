class Solution {
private:
    vector<vector<int>> ret;
    vector<int>temp;
public://争取比上一个题简化一下参数，然后要注重参数是否被应用的问题
    void setDigui(vector<int>nums,vector<int>temp){
        if(nums.size()==0){
            sort(temp.begin(),temp.end());//
          vector< vector<int> >::iterator it = find(ret.begin(),ret.end(),temp);
         if(it==ret.end())
            ret.push_back(temp);
            return;
        }
        int t = nums[0];
        nums.erase(nums.begin());
        setDigui(nums,temp);
        temp.push_back(t);
        setDigui(nums,temp);
        }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {//去重还是个二重循环
        setDigui(nums,temp);
     //  vector< vector<int> >::iterator iter = unique(ret.begin(),ret.end());//unique这种做法此处是错误的，因为它只能去除相邻的重复元素
       //无法去除不相邻的重复元素这就需要生成的时候注意一波了
    //   ret.erase(iter,ret.end());
        return ret;
        }
};
