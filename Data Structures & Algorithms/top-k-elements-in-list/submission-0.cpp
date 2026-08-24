class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        for(auto& i : nums) i += 1000;

        std::vector<int> cnt(2001, 0);
        for(std::size_t i{ 0uz }; i < nums.size(); i ++)
        {
            cnt[nums[i]] ++;
        }

        std::vector<std::size_t> idx(2001);
        for(std::size_t i{ 0uz }; i < idx.size(); i ++)
            idx[i] = i;

        std::sort(
            idx.begin(),
            idx.end(),
            [&](int a, int b)
            {
                return cnt[a] < cnt[b];
            }
        );

        std::size_t end = 2000uz;
        std::vector<int> result;

        while(k -- )
        {
            result.emplace_back(static_cast<int>(idx[end]) - 1000);
            end --;
        }

        return result;
    }
};
