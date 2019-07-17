class Solution {
public:
    bool isValid(string s) {
        if(s.length()==0){
            return true;
        }
        map<char,char> m;
        m['(']=')';
        m['[']=']';
        m['{']='}';
        stack<char> data;
        for(int i=0;i<s.length();i++){           
            if(s[i]=='('||s[i]=='['||s[i]=='{'){
                data.push(s[i]);
            }
            else{
                if(data.empty()){
                    return false;
                }
                if(s[i]==m[data.top()]){
                    data.pop();
                }
                else{
                    return false;
                }

            }
        }
        return data.empty();
        
    }
};