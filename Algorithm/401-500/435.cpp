class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n==0)
        {
            return 0;
        }
        int ans = 1;
        sort(intervals.begin(),intervals.end(),[](const auto&a,const auto&b){
            return a[1]<b[1];
        });
        int right = intervals[0][1];
        for(int i =1;i<n;++i)
        {
            if(intervals[i][0]>=right)
            {
                ans++;
                right = intervals[i][1];
            }
        }
        return n-ans;
    }
};
