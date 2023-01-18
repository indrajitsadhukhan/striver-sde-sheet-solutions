class Solution {
    
public:
    void nextPermutation(vector<int>& nums) {
        int n =nums.size();
        int pos1=-1;
        for(int i=n-1;i>0;i--)
        {
            if(nums[i-1]<nums[i])
            {
                pos1=i-1;
                break;
            }
        }
        int pos2=0;
        if(pos1>=0)
        {
            for(int i=n-1;i>=0;i--)
            {
                if(nums[i]>nums[pos1])
                {
                    pos2=i;
                    break;
                }
            }
                    swap(nums[pos1],nums[pos2]);

        }
        reverse(nums.begin()+pos1+1,nums.end());
    }
};
