//当满足（1，x-1）时，补充x即可满足（1，2x-1）

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int patches = 0;
        long long x = 1;
        int count = nums.size(),index = 0;
        while(x<=n)
        {
            if(index<count && nums[index]<=x)
            {
                x+=nums[index];
                index++;
            }
            else
            {
                x <<= 1;
                patches++;
            }
        }
        return patches;
    }
};
