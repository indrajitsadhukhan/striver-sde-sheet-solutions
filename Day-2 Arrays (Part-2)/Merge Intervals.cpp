class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> new_intervals;
        int i=0;
        while(i<n)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];
            
            if(new_intervals.empty() || new_intervals.back()[1]<intervals[i][0])
                new_intervals.push_back(intervals[i]);
            else
            {
                new_intervals.back()[1]=max(new_intervals.back()[1],intervals[i][1]);
            }
            i++;
        }
        return new_intervals;
    }
};
