class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int cand1=-1,cand2=-1,vote1=0,vote2=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==cand1)
                vote1++;
            else if(nums[i]==cand2)
                vote2++;
            else if(vote1==0)
                cand1=nums[i],vote1++;
            else if(vote2==0)
                cand2=nums[i],vote2++;
            else
                vote1--,vote2--;
        }
        int c1=0,c2=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==cand1)
                c1++;
            if(nums[i]==cand2)
                c2++;
        }
        if(c1>n/3)
            res.push_back(cand1);
        if(cand1!=cand2 && c2>n/3)
            res.push_back(cand2);
        return res;
    }
};