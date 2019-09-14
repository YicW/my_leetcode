class Solution {
private:
    void helper(vector<int>& nums,int coins, int& ans)
    {
        if(nums.size()==0)
        {
            ans=max(ans,coins);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            int tmp=nums[i];
            int delta=nums[i]*(i-1<0?1:nums[i-1])*(i+1>nums.size()-1?1:nums[i+1]);
            nums.erase(nums.begin()+i);
            helper(nums,coins+delta,ans);
            nums.insert(nums.begin()+i,tmp);
        }
    }
public:
    int maxCoins(vector<int>& nums) {
        int ans=0;
        helper(nums,0,ans);
        return ans;
    }
};
