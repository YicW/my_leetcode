class Solution {
public:
    bool canJump(vector<int>& nums) {
        auto len = nums.size();
        int i;
        if (len <= 1)
            return true;
        auto remain_size = len - 1;//start index i.e. rbegin()
        bool break_flag = false;
        while (1)
        {
            for ( i = remain_size - 1; i >= 0; i--)
            {
                if (nums[i] >= (remain_size - i))
                {
                    remain_size = i;
                    if (remain_size == 0)
                        return true;
                    break;
                }
            }
            if(i==-1)
                return false;           
        }
    }
};
