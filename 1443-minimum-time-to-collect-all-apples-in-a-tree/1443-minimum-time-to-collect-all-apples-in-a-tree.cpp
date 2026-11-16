class Solution {

private:
    int DFS(int curr, vector<bool>& visited , vector<vector<int>>&adj, vector<bool>&hasapple){
        visited[curr] = true;
        int totaltime = 0;
        for(int neighbour : adj[curr]){
            if (!visited[neighbour]) {
            int timefromchild = DFS(neighbour , visited , adj , hasapple);

                if(timefromchild>0||hasapple[neighbour]){
                    totaltime += timefromchild+2;
                }
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

        vector<bool> visited(n, false);

        return DFS(0,visited,adj,hasApple);
    }
};