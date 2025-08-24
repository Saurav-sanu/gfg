class Solution {
  public:
    vector<int>result;
    void dfs(vector<vector<int>>& adj,vector<bool>&visited,int u){
        if(visited[u]==true){
            return;
        }
        visited[u]=true;
        result.push_back(u);
        for(int &v:adj[u]){
            if(!visited[v]){
                dfs(adj,visited,v);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<bool>visited(n,false);
        
        dfs(adj,visited,0);
        return result;
        
    }
};