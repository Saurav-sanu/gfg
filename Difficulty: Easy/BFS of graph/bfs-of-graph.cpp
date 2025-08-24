class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        vector<int>result;
        queue<int>q;
        vector<bool>visited(adj.size(),false);
        q.push(0);
        visited[0]=true;
        
        
        while(!q.empty()){
            auto u=q.front();
            q.pop();
            result.push_back(u);
            
            for(auto &v:adj[u]){
                if(!visited[v]){
                    q.push(v);
                    visited[v]=true;
                }
            }
        }
        return result;
        
        
    }
};