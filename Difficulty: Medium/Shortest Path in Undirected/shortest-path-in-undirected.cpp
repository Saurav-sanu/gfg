//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

//Back-end complete function Template for C++


// } Driver Code Ends

class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
    //using bfs 
    
    //since all has a unit weight
        int n=adj.size();
        vector<int>dist(n,-1);
        
        queue<int>q;
        q.push(src);
        dist[src]=0;
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(auto vec:adj[node]){
                if(dist[vec]==-1){
                    dist[vec]=dist[node]+1;
                    q.push(vec);
                }
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int src;
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(adj, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
        cout << "~\n";
    }
}

// } Driver Code Ends