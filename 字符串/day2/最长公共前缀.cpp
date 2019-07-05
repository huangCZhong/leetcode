class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
/*
解题思路：
1.如果字符串数组内不包含任何字符串，则返回空字符
2 首先将第一个字符串与第二个字符串相比得到公共前缀，然后将该公共前缀与下一个字符串比较得到另一个公共前缀，依次比较字符串数组中所有的字符串，返回最后的公共前缀。

时间复杂度：O(n2)，空间复杂度：O(n)
*/
        if(strs.size()==0){
            return "";
        }
        string temp=strs[0];
        string ans;
        for(auto str :strs){
            ans="";
            int s1=temp.size();
            int s2=str.size();
            for(int j=0;j<min(s1,s2);j++){
                if(temp[j]==str[j]){
                    ans+=temp[j];
                }
                else{
                    break;
                }
            }
            temp=ans;
        }
        return temp;
    }
};