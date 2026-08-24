class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<std::pair<std::string, std::string*>> mp;

        for(std::size_t i{ 0u }; i < strs.size(); i ++)
        {
            std::string str = strs[i];
            std::sort(str.begin(), str.end());
            mp.emplace_back(str, &strs[i]);
        }

        std::sort(mp.begin(), mp.end());

        std::vector<std::vector<std::string>> result;
        std::vector<std::string> buff;

        buff.emplace_back(*(mp[0].second));
    
        for(std::size_t i{ 1u }; i < strs.size(); i ++)
        {
            if(mp[i].first == mp[i - 1].first)
            {
                buff.emplace_back(*(mp[i].second));
            }else
            {
                result.emplace_back(std::move(buff));
                buff.emplace_back(*(mp[i].second));
            }
        }

        if(buff.size())
            result.emplace_back(std::move(buff));

        return result;
    }
};

