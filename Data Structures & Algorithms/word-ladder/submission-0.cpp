class Solution {
private:
    std::vector<std::vector<int>> g;
    std::vector<int> dis;

    int cnt_diff(const std::string& str, const std::string& ttr)
    {
        if(str.size() != ttr.size())
            return 100;
        
        int cnt = 0;
        for(int i = 0; i < str.size(); i ++)
            cnt += (str[i] != ttr[i]);

        return cnt;
    }

    void build_edges(std::vector<std::string>& wordList)
    {
        for(int i = 0; i < wordList.size(); i ++)
        {
            for(int j = i + 1; j < wordList.size(); j ++)
            {
                int cnt = cnt_diff(wordList[i], wordList[j]);
                if(cnt == 1)
                {
                    g[i].emplace_back(j);
                    g[j].emplace_back(i);
                }
            }
        }
    }

    void bfs(int start)
    {
        std::queue <int> q;
        q.push(start);
        dis[start] = 0;
        
        while(!q.empty())
        {
            int v = q.front();
            q.pop();
            for(auto& u : g[v])
            {
                if(dis[u] == -1)
                {
                    dis[u] = dis[v] + 1;
                    q.push(u);
                }
            }
        }
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.emplace_back(beginWord);

        g.resize(wordList.size());
        dis.resize(wordList.size(), -1);

        build_edges(wordList);

        bfs(wordList.size() - 1);

        int result = -1;

        for(int i = 0; i < wordList.size(); i ++)
        {
            if(wordList[i] == endWord)
            {
                if(dis[i] == -1) continue;
                if(dis[i] < result || result == -1)
                    result = dis[i];
            }
        }

        return result + 1;
    }
};
