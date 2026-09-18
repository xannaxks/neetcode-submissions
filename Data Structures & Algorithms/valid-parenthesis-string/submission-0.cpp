class Solution {
public:
    bool checkValidString(string s) {
        int balance = 0;
    
        std::vector<char> astrisks;
        astrisks.reserve(std::count(s.begin(), s.end(), '*'));
    
        for(int i = 0; i < s.size(); i ++)
            if(s[i] == '*') astrisks.push_back(i);
        
        std::reverse(astrisks.begin(), astrisks.end());

        for(int i = 0; i < s.size(); i ++)
        {
            if(s[i] == '(') balance ++;
            else if(s[i] == ')') balance --;

            if(balance < 0)
            {
                if(astrisks.empty())
                    return false;
                if(astrisks.back() > i)
                    return false;

                balance ++;
                s[astrisks.back()] = '(';
                astrisks.pop_back();
            }
        }

        std::reverse(astrisks.begin(), astrisks.end());
        balance = 0;

        for(int i = s.size() - 1; i >= 0; i --)
        {
            if(s[i] == ')') balance ++;
            else if(s[i] == '(') balance --;

            if(balance < 0)
            {
                if(astrisks.empty())
                    return false;
                if(astrisks.back() < i)
                    return false;

                balance ++;
                s[astrisks.back()] = ')';
                astrisks.pop_back();
            }
        }

        return true;
    }
};
