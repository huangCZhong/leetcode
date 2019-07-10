class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
/*
解题思路：
从二维数组的右上方开始查找

时间复杂度：O(n)，空间复杂度：O(1)
*/
        if(matrix.size()==0){
            return false;
        }
        int rows=matrix.size();
        int cols=matrix[0].size();
        int row=0;
        int col=cols-1;
        while(row<rows&&col>=0){
            if(target==matrix[row][col]){
                return true;
            }
            else if(target<matrix[row][col]){
                col--;
            }
            else{
                row++;
            }
        }
        return false;
    }
};