class Solution {
public://堆栈的简单应用
/*
 堆栈的结构体如下：
  typedef struct
  {
      datatype stack[MaxStackSize];//此处可用vector，双向队列等代替
      int top;
  }SeqStack;
  */
    bool isValid(string s) {
        stack<char, vector<char> >st;//此处的意思是用vector<cahr>来构建堆栈的意思；
        for(int i=0;i<s.length();i++){
            if(s[i]=='{'||s[i]=='[' || s[i]=='('){
                st.push(s[i]);
                    }
           else if(s[i]=='}'||s[i]==']'||s[i]==')'){//这个地方if和else
            //if的区别就在于if前面如果执行了则后面的都要进行判断；而elseif如果前面自信了那么后面则不会执行就是这样
                if(s[i]=='}'){//此处每一步都要考虑堆栈是否为空，如果为空，证明不匹配，即需要排除右比左多的情况
                    if(!st.empty() && st.top()=='{')
                    st.pop();
                    else 
                    return false;
                }
                else if(s[i]==']'){
                    if(!st.empty() && st.top()=='[')
                    st.pop();
                    else
                    return false;
                    }
                else if(s[i]==')'){
                    if(!st.empty() && st.top()=='(')
                    st.pop();
                    else
                    return false;
                }
            }
            }
         if(st.empty()) return true; 
         else return false;
            }
};
