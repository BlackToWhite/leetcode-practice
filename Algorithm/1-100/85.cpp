// 画柱状图
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0)
        {
            return 0;
        }
        int m =matrix[0].size();
        vector<vector<int>> vec(n,vector<int>(m,0));
        for(int i =0;i<n;++i)
        {
            for(int j =0;j<m;++j)
            {
                if(matrix[i][j]=='1')
                {
                    vec[i][j] = (j==0?0:vec[i][j-1])+1;
                }
            }
        }
        int ret = 0;
        for(int i =0;i<n;++i)
        {
            for(int j =0;j<m;++j)
            {
                if(matrix[i][j]=='0')
                {
                    continue;
                }
                int width = vec[i][j];
                int area = width;
                for(int k = i-1;k>=0;--k)
                {
                    width = min(vec[k][j],width);
                    area = max(area,width*(i-k+1));
                }
                ret = max(ret,area);
            }
        }
        return ret;
    }
};
