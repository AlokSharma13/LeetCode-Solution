class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int landcount = 0;

        queue<pair<int,int>>q;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    landcount++;
                }
            }
        }

        if(landcount == 0 || landcount == n*n){
            return -1;
        }

        int dist = -1;
        while(!q.empty()){
            int size = q.size();
            dist++;
            while(size>0){
                // int x = q.front().first();
                // int y = q.front().second();
                auto[x,y] = q.front();
                q.pop();
                size--;

                int dx[] = {-1,1,0,0};
                int dy[] = {0,0,-1,1};

                for(int k = 0; k<4; k++){
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny] == 0){
                        grid[nx][ny] = true;
                        q.push({nx,ny});
                    }
                }


            }
        }
        return dist;



    }
};