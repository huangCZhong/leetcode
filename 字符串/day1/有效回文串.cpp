class Solution {
public:
    bool isPalindrome(string s) {
		//思路：构建两个指针
		//isalnum()用于判断字符是否是数字或字母
		//tolower()将字母转成小写
        int n=s.size(), left=0, right=n-1;
        while(left<right){
            while(left<right&&!isalnum(s[left])){
                left++;
            }
            while(left<right&&!isalnum(s[right])){
                right--;
            }
            if(tolower(s[left++])!=tolower(s[right--])){
                return false;
            }
        }
        return true;
    }
};