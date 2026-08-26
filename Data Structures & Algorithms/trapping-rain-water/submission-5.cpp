class Solution
{
private:
    std::vector<std::size_t> get_pillars(std::vector<int>& height)
    {
        std::vector<std::size_t> result;
        for(std::size_t i = { 0u }; i < height.size(); i ++)
        {   
            if(i == height.size() - 1u)
            {
                if(height[i] >= height[i - 1])
                    result.emplace_back(i);
                continue;
            }

            int j = i + 1;
            while(j < height.size() && height[j] == height[i])
                j ++;

            if(j < height.size())
            {
                if(i == 0u && height[i] > height[j])
                    result.emplace_back(i);

                if(i != 0u && height[i] > height[j] && height[i] > height[i - 1])
                    result.emplace_back(i);
            }else
            {
                if(i != 0 && height[i] > height[i - 1])
                    result.emplace_back(i);
            }
            i = j - 1;
        }

        return result;
    }

public:
    int trap(vector<int>& height)
    {
        if(height.size() <= 2)
            return 0;
        int cnt = 0;
        while(true)
        {
            std::vector<std::size_t> pillars = std::move(this->get_pillars(height));
            // for(auto i : pillars)
            //     std::cout << i << " ";
            // std::cout << std::endl;
            if(pillars.size() < 2u)
                break;
            for(std::size_t i{ 0u }; i < pillars.size() - 1u; i ++)
            {
                int pillar1 = height[pillars[i]], pillar2 = height[pillars[i + 1]];
                for(int j = pillars[i] + 1; j < pillars[i + 1]; j ++)
                {
                    cnt += std::max(0, std::min(pillar1, pillar2) - height[j]);
                    height[j] = std::max(height[j], std::min(pillar1, pillar2));
                }
            }
            // for(auto i : height)
            //     std::cout << i << " ";
            // std::cout << std::endl;
        }
        return cnt;
    }
};