class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,n);
        dp[0]=0;
        for(int i = 0;i<=n;i++){
            for(int j=0;j*j<=i;j++){
                int square = j*j;
                dp[i] = min(dp[i],dp[i-square]+1);
            }
        }
        return dp[n];
    }
};