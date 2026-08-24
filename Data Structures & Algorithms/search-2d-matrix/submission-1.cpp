class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        std::size_t n = matrix.size(), m = matrix.front().size();
        std::size_t l = 0, r = n * m - 1uz;

        while(l < r)
        {
            std::size_t mid = (l + r) >> 1uz;

            if(matrix[mid / m][mid % m] >= target) r = mid;
            else l = mid + 1;
        }

        if(matrix[r / m][r % m] == target) 
            return true;
        return false;
    }
};
