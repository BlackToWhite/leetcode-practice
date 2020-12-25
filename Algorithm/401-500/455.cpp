class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ret = 0;
        int n = g.size(),m = s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int j = 0;
        for(int i =0;i<n;++i)
        {
            while(j<m&&s[j]<g[i])
            {
                j++;
            }
            if(j==m)
            {
                break;
            }
            ret+=1;
            j++;
        }
        return ret;
    }
};
