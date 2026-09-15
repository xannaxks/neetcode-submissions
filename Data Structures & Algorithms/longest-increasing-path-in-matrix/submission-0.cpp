class Solution {
private:
    std::vector<std::vector<int>> used;

    int diri[4] = {0, 0, 1, -1};
    int dirj[4] = {1, -1, 0, 0};

    void dfs(int i, int j, const std::vector<std::vector<int>>& matrix)
    {
        used[i][j] = 1;
        for(int dir = 0; dir < 4; dir ++)
        {
            int ni = i + diri[dir], nj = j + dirj[dir];

            if(
                ni >= 0 &&
                ni < matrix.size() &&
                nj >= 0 &&
                nj < matrix[0].size() &&
                matrix[ni][nj] > matrix[i][j]
            )
            {
                if(!used[ni][nj])
                    dfs(ni, nj, matrix);

                used[i][j] = std::max(used[i][j], used[ni][nj] + 1);
            }
        }
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        used.resize(matrix.size(), std::vector<int>(matrix[0].size(), 0));

        for(int i = 0; i < matrix.size(); i ++)
        {
            for(int j = 0; j < matrix[0].size(); j ++)
            {
                if(!used[i][j])
                    dfs(i, j, matrix);
            }
        }

        int result = used[0][0];

        for(auto& i : used)
        {
            for(auto& j : i)
            {
                // std::cout << j << " ";
                result = std::max(result, j);
            }
            // std::cout << std::endl;
        }
    
        return result;
    }
};
