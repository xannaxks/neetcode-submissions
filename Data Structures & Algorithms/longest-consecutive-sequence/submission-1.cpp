class Solution {
public:
    void count_(unordered_map<int, int>& hash, const vector<int>& nums)
    {
        for(auto& i : nums)
            hash[i] ++;
    }

    std::vector<int> get_starting_points(const std::vector<int>& nums,  unordered_map<int, int>& hash)
    {
        std::vector<int> result;
        for(auto& i : nums)
        {
            if(hash[i - 1] == 0)
                result.emplace_back(i);
        }
        return result;
    }

    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> hash;

        count_(hash, nums);

        std::vector<int> starting_points = get_starting_points(nums, hash);

        int mx{ 0 };

        for(auto& start : starting_points)
        {
            int cur = start + 1;
            while(hash[cur])
            {
                cur ++;
            }
            mx = max(mx, cur - start);
        }

        return mx;
    }
};
