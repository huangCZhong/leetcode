class Solution {
public:
    bool buddyStrings(string A, string B) {
/*
解题思路：
1.如果两个字符串长度不相等，则不满足要求
2.如果两个字符串中只有两个位置对应的字符不相同，则如果两个字符串中这两个位置对应的字符串正好错位，则满足要求
3.如果这两个字符串对应位置的字符都相同，则只需有一个字符重复出现就满足要求

时间复杂度：O(n)，空间复杂度：O(n)
*/
        if(A.size()!=B.size()){
            return false;
        }
        vector<pair<char,char>> diff;
        unordered_map<char,int> um;
        for(int i=0;i<A.size();i++){
            if(A[i]!=B[i]){
                diff.push_back({A[i],B[i]});
            }
            else{
                um[A[i]]++;
            }
        }
        if(diff.size()==2){
            if(diff[0].first==diff[1].second&&diff[0].second==diff[1].first){
                return true;
            }
        }
        if(diff.size()==0){
            for(auto& x : um){
                if(x.second>1){
                    return true;
                }
            }
        }
        return false;
    }
};