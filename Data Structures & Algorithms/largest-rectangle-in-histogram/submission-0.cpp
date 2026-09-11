class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        std::stack<int> monotonic_stack;
        std::vector<int> left_border, right_border;
        
        left_border.resize(heights.size());
        right_border.resize(heights.size());

        int result = 0;

        for(int i = 0; i < heights.size(); i ++)
        {
            while(
                monotonic_stack.size() &&
                heights[monotonic_stack.top()] > heights[i]
            )
            {
                int idx = monotonic_stack.top();
                monotonic_stack.pop();
                right_border[idx] = i;
            }

            monotonic_stack.push(i);
        }

        while(monotonic_stack.size())
        {
            int idx = monotonic_stack.top();
            monotonic_stack.pop();
            right_border[idx] = heights.size();
        }

        for(int i = heights.size() - 1; i >= 0; i --)
        {
            while(
                monotonic_stack.size() && 
                heights[monotonic_stack.top()] > heights[i]
            )
            {
                int idx = monotonic_stack.top();
                monotonic_stack.pop();
                left_border[idx] = i;
            }
            monotonic_stack.push(i);
        }
        
        while(monotonic_stack.size())
        {
            int idx = monotonic_stack.top();
            monotonic_stack.pop();
            left_border[idx] = -1;
        }

        for(int i = 0; i < heights.size(); i ++)
        {
            result = std::max(result, (right_border[i] - left_border[i] - 1) * heights[i]);
        }

        return result;
    }
};
