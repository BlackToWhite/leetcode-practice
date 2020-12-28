//buy[i][j]表示恰好进行j笔交易，手头持有股票的收益
//sell[i][j]表示恰好进行j笔交易，手头不持有股票的收益

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n==0)
        {
            return 0;
        }
        k = min(k,n/2);
        vector<vector<int>> buy(n,vector<int>(k+1));
        vector<vector<int>> sell(n,vector<int>(k+1));
        buy[0][0]=-prices[0];
        sell[0][0]=0;

        for(int i =1;i<=k;++i)
        {
            sell[0][i]=buy[0][i]=INT_MIN/2;
        }

        for(int i =1;i<n;++i)
        {
            buy[i][0]=max(buy[i-1][0],sell[i-1][0]-prices[i]);
            for(int j =1;j<=k;++j)
            {
                buy[i][j]=max(buy[i-1][j],sell[i-1][j]-prices[i]);
                sell[i][j]=max(sell[i-1][j],buy[i-1][j-1]+prices[i]);
            }
        }
        int max = 0;
        for(int i =0;i<=k;++i)
        {
            if(sell[n-1][i]>max)
            {
                max=sell[n-1][i];
            }
        }
        return max;
    }
};
