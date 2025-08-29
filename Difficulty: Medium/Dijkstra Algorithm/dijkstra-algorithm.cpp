// User Function Template
class Solution {
  public:
  typedef pair<int,int>p;
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        unordered_map<int,vector<p>>adj;
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            int wt=e[2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,src});
        
        vector<int>result(V,INT_MAX);
        result[src]=0;
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            int wt=top.first;
            int node=top.second;
            
            for(auto &vec:adj[node]){
                int d=vec.second;
                int othernode=vec.first;
                
                if(wt+d<result[othernode]){
                    result[othernode]=wt+d;
                    pq.push({wt+d,othernode});
                }
            }
        }
        return result;
    }
};