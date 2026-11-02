class Solution {
public:
    int solve(int i,int s, vector<int>& nums,vector<int>&dp){
        if(i<s) return 0;
        if(dp[i] != -1){
            return dp[i];
        }

        int notpicklast = nums[i]+solve(i-2,s,nums,dp);
        int picklast = solve(i-1,s,nums,dp);
        return dp[i] = max(notpicklast,picklast);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        int ans1 = solve(n-2,0,nums,dp1);
        int ans2 = solve(n-1,1,nums,dp2);
        return max(ans1,ans2);
    }
};