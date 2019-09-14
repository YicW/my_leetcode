class Solution {
private:
    vector<vector<int>> dp;
    int helper(vector<int>& nums,int i,int j)
    {
        if(i>j)
            return 0;
        if(dp[i][j]>0)
            return dp[i][j];
        for(int k=i;k<=j;k++)
        {
            int left=helper(nums,i,k-1);
            int right=helper(nums,k+1,j);
            int re=nums[k]*nums[i-1]*nums[j+1];
            dp[i][j]=max(dp[i][j],left+right+re);
        }
        return dp[i][j];
    }
public:
    
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        dp=vector<vector<int>>(nums.size(),vector<int>(nums.size(),0));
        return helper(nums,1,n);
    }
};
