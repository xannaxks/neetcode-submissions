
class Solution {
private:
    void shrink(
        int& l,
        int& r,
        int& mn,
        int& mnl, 
        int& mnr,
        std::multiset<char>& not_in_set,
        std::map<char, int>& must_be_in_set,
        std::map<char, int>& in_set_cnt,
        std::set<char>& cnt_t,
        const std::string& s,
        const std::string& t
    )
    {
        // std::cout << "shrinking\n" << l << " " << r << "\n";
            if(mn == -1)
            {
                mnr = r;
                mnl = l;
                mn = r - l + 1;
            }
            else if(r - l + 1 < mn)
            {
                mnr = r;
                mnl = l;
                mn = r - l + 1;
            }
        while(1)
        {
            l ++;

            in_set_cnt[s[l-1]] --;
            if(in_set_cnt[s[l-1]] < must_be_in_set[s[l-1]] && cnt_t.count(s[l-1]))
            {
                not_in_set.insert(s[l-1]);
                // std::cout << l << " " << r << "\n";
                return;
            }
            if(mn == -1)
            {
                mnr = r;
                mnl = l;
                mn = r - l + 1;
            }
            else if(r - l + 1 < mn)
            {
                mnr = r;
                mnl = l;
                mn = r - l + 1;
            }
        }
    }
public:
    string minWindow(string s, string t) {
        std::multiset<char> not_in_set;
        std::map<char, int> in_set_cnt, must_be_in_set;
        std::set<char> cnt_t;

        for(auto i : t) not_in_set.insert(i);
        for(auto i : t) in_set_cnt[i] = 0;  
        for(auto i : t) cnt_t.insert(i);
        for(auto i : t) must_be_in_set[i] ++;
 
        int l = 0, r = 0, mn = -1, mnl = -1, mnr = -1;

        while(r < s.size())
        {
            auto fnd = not_in_set.find(s[r]);
            if(fnd != not_in_set.end())
                not_in_set.erase(fnd);
            in_set_cnt[s[r]] ++;

            if(not_in_set.empty())
                shrink(l, r, mn, mnl, mnr, not_in_set, must_be_in_set, in_set_cnt, cnt_t, s, t);

            r ++;
        }
        // std::cout << mn << " " << mnl << " " << mnr << "\n";
        if(mn == -1)
            return "";
        
        std::string result = "";
        for(int i = mnl; i <= mnr; i ++)
            result += s[i];

        return result;
    }
};
