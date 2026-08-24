class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        std::vector<int> decay;
        for(auto& i : matrix)
        {
            for(auto& j : i)
                decay.emplace_back(j);
        }

        std::size_t l = 0uz, r = decay.size() - 1uz;

        while(l < r)
        {
            std::size_t mid = (l + r) >> 1uz;

            if(decay[mid] >= target) r = mid ;
            else l = mid + 1;
        }

        if(decay[r] == target)
            return true;
        return false;
    }
};
