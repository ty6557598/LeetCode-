class Solution {
public://这种问题是传说中的Ksum问题，比较简单，只需要用双指针的方法就可以解决。
//然后就是说我们要注意必须要首先排序才可以用双指针的方法，3sum就是说先固定一个，然后在其他值里完成2sum的任务，然后在依次类推，时间复杂度为O（n^(k-1)），然后这种题都可以用递归来做，我先实现一般的方法吧。这道题看代码可以很容易理解算法的实现的
/*
    vector<vector<int>> threeSum(vector<int>& nums) {
         vector< vector<int> >ret,ret1;
           vector<int>oneRes,temp,result,temp1;
         if(nums.size()<3) return ret;//此处返回ret是可以的，因为ret此时没有赋值的话，默认为空
         if(nums.size()==3) 
         {
         if(nums[0]+nums[1]+nums[2]==0)
         {oneRes.push_back(nums[0]); oneRes.push_back(nums[1]);oneRes.push_back(nums[2]); 
         ret.push_back(oneRes); return ret;
         }
         else return ret;
         }
         int i=0,j=0,target = 0;
         sort(nums.begin(),nums.end(),less<int>());
         for(int k=0;k<nums.size()-2;k++){
             i = k+1; j = nums.size()-1; 
             target = 0 - nums[k];
             while(i<j){
              if((nums[i]+nums[j])==target){
                  oneRes.clear();
                  oneRes.push_back(nums[k]);
                  oneRes.push_back(nums[i]);
                  oneRes.push_back(nums[j]);
                    if(ret.size() == 0 || oneRes != ret[ret.size() - 1])

                        ret.push_back(oneRes); // copy constructor
                  i++; j--;
              }
              else if(nums[i]+nums[j]>target)
                   j--;
              else
                   i++;
                   }
          }
          if(ret.empty()==1) return ret;
          /*
          for(int m=0;m<ret.size()-1;m++){
              
              temp = ret[m];
              for(int n=m+1;n<ret.size();n++){
                  temp1 = ret[n];
                if((temp[0]==temp1[0]||temp[0]==temp1[1]||temp[0]==temp1[2])&&(temp[1]==temp1[0]||temp[1]==temp1[1]||temp[1]==temp1[2])&&(temp[2]==temp1[0]||temp[2]==temp1[1]||temp[2]==temp1[2]))
                  result.push_back(n);
                  }
              ret1.push_back(ret[m]);
              for(int q=0;q<result.size();q++)
              ret.erase(ret.begin()+result[q]-q);
              }
               return ret1;
             
               vector< vector<int> >::iterator iter = unique(ret.begin(),ret.end());
               ret.erase(iter,ret.end());
               return ret;
               }
               */
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector< vector<int> >vecResult;
      if(nums.size() < 3) return vecResult;
       vector<int>vecTriple(3, 0);
      sort(nums.begin(), nums.end());
       int iCurrentValue = nums[0];
       int iCount = nums.size() - 2; // (1) trick 1
    for(int i = 0; i < iCount; ++i) {

            if(i && nums[i] == iCurrentValue) { // (2) trick 2: trying to avoid repeating triples

                continue;

            }

            // do 2 sum

            vecTriple[0] = nums[i];

            int j = i + 1;

            int k = nums.size() - 1;

            while(j < k) {

                int iSum = nums[j] + nums[k];

                if(iSum + vecTriple[0] == 0) {

                    vecTriple[1] = nums[j];

                    vecTriple[2] = nums[k];

                    vecResult.push_back(vecTriple); // copy constructor

                    ++j;

                    --k;

                }

                else if(iSum + vecTriple[0] < 0)

                    ++j;

                else

                    --k;

            }

            iCurrentValue = nums[i];

       }
        vector< vector<int> >::iterator it = unique(vecResult.begin(), vecResult.end());

        vecResult.resize( distance(vecResult.begin(), it) );

        return vecResult;

    }

};
