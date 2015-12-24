class Solution {
private:
   vector<string> ret;
   map<char, string> str;    

public://这道题用到的方法是穷举遍历，它属于回溯的一种，可以说是没有限定条件的回溯
   void dfs(int deep,int maxDeep,string &s,string ans){
       if(deep == maxDeep){//退出的条件，此处maxDeep是digits.length(),因为要把最后一步考虑完之后才应该推出
           ret.push_back(ans);//变量写在private里面是共用参数的方法，这样调用的时候没有变量的赋值什么的司马东西
           return;
           }
       for(int i=0;i<str[s[deep]].size();i++){
           dfs(deep+1,maxDeep,s,ans+str[s[deep]][i]);//此处意思是进行3次递归调用，此处写deep+1是没有什么问题的，因为调用关系是deep = deep+1,
           //所以deep的值会增大的
           }//重复做某项过程的时候可以用递归来做，只是需要考虑一下递归的设计问题
       }
   vector<string> letterCombinations(string digits) {
           if(digits.length()==0) return ret;
            str['0']="";str['1']="";str['2']="abc";
            str['3']="def";str['4']="ghi";str['5']="jkl";
            str['6']="mno";str['7']="pqrs";str['8']="tuv";str['9']="wxyz";
        dfs(0,digits.length(),digits,"");//第四个参数是返回的值
        return ret;
    }
};
