class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::map<int, int> mp;

        auto print_mp=[&]()
        {
            for(auto& [i, j] : mp)
                std::cout << i << " -> " << j << "\n";
            std::cout << "\n";
        };

        std::vector<int> result;
        
        for(int i = 0; i < k; i ++)
            mp[nums[i]] ++;

        // print_mp();

        result.emplace_back(mp.rbegin()->first);

        for(int i = k; i < nums.size(); i ++)
        {
            mp[nums[i - k]] --;
            if(mp[nums[i - k]] == 0)
            {
                mp.erase(mp.find(nums[i - k]));
            }
            mp[nums[i]] ++;
            result.emplace_back(mp.rbegin()->first);
            // print_mp();
        }

        return result;
    }
};
