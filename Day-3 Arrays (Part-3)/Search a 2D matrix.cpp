class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        int left=0,right=m*n-1;
        while(left<right)
        {
            int mid = (0ll+left+right)/2;
            if(matrix[mid/n][mid%n]<target)
            {
                left=mid+1;
            }
            else{
                right=mid;
            }
        }
        // 10/4 10%4 - > 3 1
        if(matrix[left/n][left%n]==target)
            return true;
        return false;
    }
};