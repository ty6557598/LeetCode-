class Solution {
    //这个问题就是传说中的卡特兰数问题，无论是车票找零问题，固定节点下二叉树个数的问题等等就是卡特兰数。这种问题可以用递归构造二叉树来做
    //卡特兰数返回所有值的问题可以通过穷举递归的方法来做
private:
vector<string> strNums;
public:
vector<string> generateParenthesis(int n) {
string s = "";
generateBinary_Tree(n,n,s,strNums);
 return strNums;
    }
    //这道题的方法是穷极递归，比一般的回溯算法要简单（例如八皇后问题），每个决策点有两种决策
void generateBinary_Tree(int leftN,int rightN,string s,vector<string>&strNums){
	if(leftN==0 && rightN==0)
	{
        strNums.push_back(s);
		return;
	}
    if(leftN>0){
	  generateBinary_Tree(leftN-1,rightN,s+'(',strNums);	  
	}
	if( right>0 && leftN<rightN){
      generateBinary_Tree(leftN,rightN-1,s+')',strNums);
}
}
};
