//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User Function Template
class Solution {
  public:
  typedef pair<int,int>P;
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        int n=adj.size();
        vector<int>result(n,INT_MAX);
        
        priority_queue<P,vector<P>,greater<P>>pq;
        result[src]=0;
        
        pq.push({0,src});
        
        while(!pq.empty()){
            auto element=pq.top();
            pq.pop();
            
            int dist=element.first;
            int node=element.second;
            
            for(auto &v:adj[node]){
                int adjNode=v.first;
                int wt=v.second;
                
                if(dist+wt<result[adjNode]){
                    result[adjNode]=dist+wt;
                    pq.push({dist+wt,adjNode});
                }
                
            }
        }
        return result;
        
        
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends