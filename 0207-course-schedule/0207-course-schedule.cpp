class Solution {
    bool iscycle(int src,vector<bool>&vis,vector<bool>&recPath,vector<vector<int>>&edge){
        vis[src]=true;
        recPath[src]=true;
        for(int i=0;i<edge.size();i++){
            int u=edge[i][0];
            int v=edge[i][1];
            if(u==src){
                if(!vis[v]){
                    if(iscycle(v,vis,recPath,edge)){
                        return true;
                    }
                }
                if(recPath[v]){
                    return true;
                }
            } 
        }
        recPath[src]=false;
        return false;
    }
public:
    bool canFinish(int n, vector<vector<int>>& edge) {
        vector<bool>vis(n,false);
        vector<bool>recPath(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(iscycle(i,vis,recPath,edge)){
                    return false;
                }
            }
        }
        return true;
    }
};