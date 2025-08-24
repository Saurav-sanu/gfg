class Solution {
  public:
  bool dfs(vector<vector<int>> &adj,int &u, vector<bool>&visited, vector<bool>&inRecursion){
      visited[u]=true;
      inRecursion[u]=true;
      
      for(auto &v:adj[u]){
          if(!visited[v]){
              if(dfs(adj,v,visited,inRecursion)){
                  return true;
              }
          }
          else if(inRecursion[v]==true){
              return true;
          }
      }
      inRecursion[u]=false;
      return false;
  }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<bool>visited(V,false);
        
        vector<bool>inRecursion(V,false);
         vector<vector<int>> adj(V);
        for (auto &e : edges) adj[e[0]].push_back(e[1]);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(adj,i,visited,inRecursion)){
                    return true;
                }
            }
        }
        return false;
        
    }
};