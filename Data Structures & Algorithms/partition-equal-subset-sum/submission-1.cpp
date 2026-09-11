class Solution {
private:
    int get_sum(const vector<int>& vec)
    {
        int sum = 0;
        for(int i = 0; i < vec.size(); i ++)
            sum += vec[i];
    
        return sum;
    }

public:
    bool canPartition(vector<int>& nums) {
        int sum = get_sum(nums);
        if(sum & 1)
            return false;
        
        sum >>= 1;
        std::vector<int> dp(sum + 1, 0);
        dp[0] = 1;
        for(auto coin : nums)
        {
            for(int i = dp.size() - 1; i >= 0; i --)
            {
                if(i - coin >= 0)
                    dp[i] |= dp[i - coin];
            }
        }
        for(auto i : dp)
        {
            std::cout << i << " ";
        }
        return dp[sum] == 1;
    }
};
