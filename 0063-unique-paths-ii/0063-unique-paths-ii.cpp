class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1]==1){
            return 0;
        }
        queue<pair<int,int>>q;
        q.push({0,0});
        obstacleGrid[0][0] = 1;
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[0][0] = 1;

        while(!q.empty()){
            auto[x,y] = q.front();
            q.pop();

            int dx[] = {1,0};
            int dy[] = {0,1};

            for(int k = 0; k < 2; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx>=0 && nx<m && ny>=0 && ny<n && obstacleGrid[nx][ny] == 0){
                   if(dp[nx][ny]==0){ // dp[nx][ny] == 1 why ?
                        q.push({nx,ny});
                   }

                   dp[nx][ny] += dp[x][y];
                    
                }
            }

            

        }
        return dp[m-1][n-1];

    }
};