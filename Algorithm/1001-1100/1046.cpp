class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        if(n==0)
        {
            return 0;
        }
        else if(n==1)
        {
            return stones[0];
        }
        // n>2
        sort(stones.begin(),stones.end());    
        n--;
        while(1)
        {
            int a = stones[n];
            int b = stones[n-1];
            stones.pop_back();
            stones.pop_back();
            if(a==b)
            {
                n-=2;
            }
            else
            {
                n-=1;
                stones.push_back(a-b);
            }
            if(n<=0)
            {
                break;
            }
            sort(stones.begin(),stones.end());
        }

        if(stones.empty())
        {
            return 0;
        }
        else
        {
            return stones[0];
        }
    }
};
