class Solution {
private:
    std::vector<int> ver;
    std::vector<int> diag1, diag2;

    std::vector<std::string> result;
    std::vector<std::vector<std::string>> ans;

    int get_diag1(int i, int j)
    {
        return i - j + diag1.size() / 2;
    }

    int get_diag2(int i, int j)
    {
        return i + j;
    }

    void f(int level, const int n)
    {
        if(level >= n)
        {
            ans.emplace_back(result);
            return;
        }

        std::string str = string(n, '.');

        for(int i = 0; i < n; i ++)
        {
            int current_diag1 = get_diag1(level, i);
            int current_diag2 = get_diag2(level, i);
            // if(ans.size() == n)
            // return;

            if(!ver[i] && !diag1[current_diag1] && !diag2[current_diag2])
            {
                str[i] = 'Q';
                result.emplace_back(str);

                diag1[current_diag1] = 1;
                diag2[current_diag2] = 1;
                ver[i] = 1;

                f(level + 1, n);

                ver[i] = 0;
                diag2[current_diag2] = 0;
                diag1[current_diag1] = 0;

                result.pop_back();
                str[i] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        ver.resize(n, 0);
        diag1.resize(n + n - 1, 0);
        diag2.resize(n + n - 1, 0);
        
        result.reserve(n);

        f(0, n);

        return ans;
    }
};
