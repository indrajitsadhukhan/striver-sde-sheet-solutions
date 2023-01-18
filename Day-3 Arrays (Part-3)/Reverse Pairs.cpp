class Solution {
public:
    int merge(vector<int> &nums,int low,int mid,int high)
    {
        int cnt=0,n1=mid-low+1,n2=high-mid,k=low,i=0,j=0;
        int L[n1],R[n2];
        j=mid+1;
        for(int i=low;i<=mid;i++)
        {
            while(j<=high && nums[i]/2.0>nums[j])
              j++;
        cnt+=j-(mid+1);
        }
        for(int i=0;i<n1;i++)
            L[i]=nums[low+i];
        for(int i=0;i<n2;i++)
            R[i]=nums[mid+1+i];
        i=0,j=0;
        while(i<n1 && j<n2)
        {
            if(L[i]<=R[j])
            nums[k++]=L[i++];
            else
                nums[k++]=R[j++];
        }
        while(i<n1)
            nums[k++]=L[i++];
        while(i<n2)
            nums[k++]=R[i++];
        return cnt;
        
    }
    int mergeSort(vector<int> &nums,int low,int high)
    {
        if(low>=high) 
            return 0;
        int mid = low+(high-low)/2;
        int ans=mergeSort(nums,low,mid);
        ans+=mergeSort(nums,mid+1,high);
        ans+=merge(nums,low,mid,high);
        return ans;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};