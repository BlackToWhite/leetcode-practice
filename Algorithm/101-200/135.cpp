//two traversal
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int>left(n);
        for(int i =0;i<n;++i)
        {
            if(i>0&&ratings[i-1]<ratings[i])
            {
                left[i]=left[i-1]+1;
            }
            else
            {
                left[i]=1;
            }
        }
        int right = 0,ret = 0;
        for(int i = n - 1;i>=0;--i)
        {
            if(i<n-1&&ratings[i]>ratings[i+1])
            {
                right = right+1;
            }
            else
            {
                right = 1;
            }
            ret+=max(left[i],right);
        }
        return ret;
    }
};

//leetcode solution
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int ret = 1;
        int inc = 1, dec = 0, pre = 1;
        for (int i = 1; i < n; i++) {
            if (ratings[i] >= ratings[i - 1]) {
                dec = 0;
                pre = ratings[i] == ratings[i - 1] ? 1 : pre + 1;
                ret += pre;
                inc = pre;
            } else {
                dec++;
                if (dec == inc) {
                    dec++;
                }
                ret += dec;
                pre = 1;
            }
        }
        return ret;
    }
};
