class Solution {
public:
    int find(
        const std::vector<int>& nums,
        const int target,
        std::size_t l,
        std::size_t r
    )
    {
        while(l < r)
        {
            std::size_t mid = (l + r) >> 1uz;
            if(nums[mid] >= target) r = mid;
            else l = mid + 1;
        }

        return (nums[r] == target ? r : -1);
    }

    std::pair<std::size_t, std::size_t> get_break_point(
        const std::vector<int>& nums
    )
    {
        std::size_t l = 0uz, r = nums.size() - 1uz;
        while(l + 1 < r)
        {
            std::size_t mid = (l + r) >> 1uz;
            if(nums[mid] < nums[r])
                r = mid;
            else 
                l = mid; 
        }

        return std::make_pair(l, r);
    }

    int search(vector<int>& nums, int target) {
        if(nums.front() <= nums.back())
        {
            return find(nums, target, 0uz, nums.size() - 1uz);
        }
        std::pair<int, int> break_point = this->get_break_point(nums);
        
        if(target <= nums.back())
            return find(nums, target, break_point.second, nums.size() - 1uz);
        return find(nums, target, 0uz, break_point.first);
    }
};
