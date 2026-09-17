class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));
        for(int j = 0; j < m; j ++)
        {
            int cnt = 0;

            for(int i = 0; i < n; i ++)
            {
                if(t[j] == s[i])
                {
                    if(!j)
                        dp[i][j] = 1;
                    else 
                        dp[i][j] += cnt;
                }
                if(j && t[j - 1] == s[i])
                    cnt += dp[i][j - 1];
            }
        }
        int sum = 0;
        for(int i = 0; i < n; i ++) sum += dp[i][m - 1];
        return sum;
    }
};
