// greedy
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int s = flowerbed.size();
        flowerbed.insert(flowerbed.begin(),0);
        flowerbed.emplace_back(0);
        for(int i = 1;i <= s;++i)
        {
            if(flowerbed[i]==0)
            {
                if(flowerbed[i-1]==0&&flowerbed[i+1]==0)
                {
                    flowerbed[i]=1;
                    --n;
                }
            }
        }
        return n<=0;
    }
};

// leetcode solution
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int m = flowerbed.size();
        int prev = -1;
        for (int i = 0; i < m; i++) {
            if (flowerbed[i] == 1) {
                if (prev < 0) {
                    count += i / 2;
                } else {
                    count += (i - prev - 2) / 2;
                }
                if (count >= n) {
                    return true;
                }
                prev = i;
            }
        }
        if (prev < 0) {
            count += (m + 1) / 2;
        } else {
            count += (m - prev - 1) / 2;
        }
        return count >= n;
    }
};
