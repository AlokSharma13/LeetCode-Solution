class Solution {

private:
    int DFS(int curr, int par , vector<vector<int>>&adj, vector<bool>&hasapple){
        int totaltime = 0;
        for(int neighbour : adj[curr]){
            if(neighbour == par) continue;

            int timefromchild = DFS(neighbour , curr , adj , hasapple);

            if(timefromchild>0||hasapple[neighbour]){
                totaltime += timefromchild+2;
            }
        }
        return totaltime;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for(const auto& edges : edges){
            
            adj[edges[0]].push_back(edges[1]);
            adj[edges[1]].push_back(edges[0]);
        }

        return DFS(0,-1,adj,hasApple);
    }
};