class Solution {
public:
   
    int findDuplicate(vector<int>& nums) {
         auto count=[&](int x)
    {
        int cnt=0;
        for(auto i: nums)
        {
            if(i<=x)
                cnt++;
        }
        return cnt;
    };
      int low=1,high=nums.size();
        int res=-1;
        while(low<high)
        {
            int mid = (0ll+low+high)/2;
            if(count(mid)<=mid)
            {
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        return low;
    }
};
