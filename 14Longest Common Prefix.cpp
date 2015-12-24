class Solution {
public://这道题的意思是找到一组数组中的最长的通用前缀
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        unsigned int strings_num = strs.size();
        unsigned int min = strs[0].size(),k=0;
        string str="";
        for(unsigned int i=0;i<strings_num;i++){
            if(strs[i].size()<min)
            min = strs[i].size();
        }
        if(min == 0) return "";
        char temp = strs[0][0];
        for(unsigned int j=0;j<min;j++){
            for(unsigned int k=0;k<strings_num;k++){
               if(temp!=strs[k][j]) 
                return str;
            }
            temp = strs[0][j+1];
            str = str+strs[k][j];
            }
            return str;
         }
};
