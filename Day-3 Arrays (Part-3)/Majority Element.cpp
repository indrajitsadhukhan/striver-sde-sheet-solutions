class Solution {
public:
    int majorityElement(vector<int>& nums) {
  int n=nums.size(),cand=-1,vote=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==cand)
            {
                vote++;
            }
            else if(vote==0)
            {
                cand=nums[i];
            }
            else{
                vote--;
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(cand==nums[i])
                cnt++;
        }
        if(cnt>n/2)
            return cand;
        else
            return -1;
}
};