class Solution
{
public:
    int trap(vector<int>& height)
    {
        int left_max = 0, right_max = 0;
        int left_ptr = 0, right_ptr = height.size() - 1;
        int cnt = 0;

        while(left_ptr < right_ptr)
        {
            if(height[left_ptr] <= height[right_ptr])
            {
                if(height[left_ptr] >= left_max)
                {
                    left_max = height[left_ptr];
                }else
                {
                    cnt += left_max - height[left_ptr];
                }
                left_ptr ++;
            }else
            {
                if(height[right_ptr] >= right_max)
                {
                    right_max = height[right_ptr];
                }else
                {
                    cnt += right_max - height[right_ptr];
                }
                right_ptr --;
            }
        }

        return cnt;
    }
};